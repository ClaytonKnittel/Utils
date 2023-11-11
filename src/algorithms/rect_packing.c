
/**********************************************************
 *                        Includes                        *
 **********************************************************/

#include <utils/algorithms/rect_packing.h>

/**********************************************************
 *                  Forward Declarations                  *
 **********************************************************/

static packed_rect_el_t* _node_base_to_el(const rb_node_t*);

static packed_rect_row_t* _node_base_height_to_row(const rb_node_t*);
static packed_rect_row_t* _node_base_ly_to_row(const rb_node_t*);
static packed_rect_el_t* _el_freelist_terminal(const packed_rect_row_t* row);
static void _el_freelist_insert(packed_rect_el_t* after, packed_rect_el_t* el);
static void _el_freelist_remove(packed_rect_el_t* el);
static void _row_remove(packed_rect_row_t* row, packed_rect_el_t* el);

static packed_rect_row_t* _row_freelist_terminal(const rect_packing_t*);
static void _row_freelist_insert(packed_rect_row_t* after,
                                 packed_rect_row_t* row);
static void _row_freelist_find_pos(rect_packing_t*, packed_rect_row_t* row);
static void _row_freelist_remove(packed_rect_row_t* row);

/**********************************************************
 *               Red-Black Tree Definitions               *
 **********************************************************/

static int _rb_cmp_packed_rect_el(const rb_node_t* a_ptr,
                                  const rb_node_t* b_ptr) {
  const packed_rect_el_t* a = _node_base_to_el(a_ptr);
  const packed_rect_el_t* b = _node_base_to_el(b_ptr);
  return a->lx < b->lx ? -1 : a->lx == b->lx ? 0 : 1;
}

RB_DEFINE_TYPE(packed_rect_el, _rb_cmp_packed_rect_el)

static int _rb_cmp_packed_rect_row_height(const rb_node_t* a_ptr,
                                          const rb_node_t* b_ptr) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Warray-bounds"
  const packed_rect_row_t* a = _node_base_height_to_row(a_ptr);
  const packed_rect_row_t* b = _node_base_height_to_row(b_ptr);
  return a->h < b->h ? -1 : a->h == b->h ? 0 : 1;
#pragma GCC diagnostic pop
}

RB_DEFINE_TYPE(packed_rect_row_height, _rb_cmp_packed_rect_row_height)

static int _rb_cmp_packed_rect_row_ly(const rb_node_t* a_ptr,
                                      const rb_node_t* b_ptr) {
  const packed_rect_row_t* a = _node_base_ly_to_row(a_ptr);
  const packed_rect_row_t* b = _node_base_ly_to_row(b_ptr);
  return a->ly < b->ly ? -1 : a->ly == b->ly ? 0 : 1;
}

RB_DEFINE_TYPE(packed_rect_row_ly, _rb_cmp_packed_rect_row_ly)

/**********************************************************
 *                    Element Helpers                     *
 **********************************************************/

static packed_rect_el_t* _node_base_to_el(const rb_node_t* rb_node_base) {
  return (packed_rect_el_t*) (((uint8_t*) rb_node_base) -
                              offsetof(packed_rect_el_t, rb_node_base));
}

/*
 * Creates a new empty rectangle element object, initializing the given fields
 * without inserting it into any of the data structures it will eventually be a
 * member of.
 */
static packed_rect_el_t* _alloc_empty_el(packed_rect_coord_t lx,
                                         packed_rect_coord_t w) {
  packed_rect_el_t* el = (packed_rect_el_t*) malloc(sizeof(packed_rect_el_t));
  if (el == NULL) {
    return NULL;
  }

  el->lx = lx;
  el->w = w;

  return el;
}

/*
 * Creates a new allocated rectangle element object.
 */
static packed_rect_el_t* _alloc_el(packed_rect_coord_t lx,
                                   packed_rect_coord_t ly,
                                   packed_rect_coord_t w, packed_rect_coord_t h,
                                   bool rotated) {
  packed_rect_el_t* el = (packed_rect_el_t*) malloc(sizeof(packed_rect_el_t));
  if (el == NULL) {
    return NULL;
  }

  el->lx = lx;
  el->ly = ly;
  el->w = w;
  el->h = h;
  el->rotated = rotated;

  return el;
}

void packed_rect_el_free(packed_rect_el_t* el) {
  free(el);
}

static uint64_t _calc_el_loss(packed_rect_coord_t dst_w,
                              packed_rect_coord_t dst_h, packed_rect_coord_t w,
                              packed_rect_coord_t h) {
  (void) dst_w;
  return w * dst_h - w * h;
}

/**********************************************************
 *                      Row Helpers                       *
 **********************************************************/

static packed_rect_row_t* _node_base_height_to_row(
    const rb_node_t* rb_node_base) {
  return (
      packed_rect_row_t*) (((uint8_t*) rb_node_base) -
                           offsetof(packed_rect_row_t, rb_node_base_height));
}

static packed_rect_row_t* _node_base_ly_to_row(const rb_node_t* rb_node_base) {
  return (packed_rect_row_t*) (((uint8_t*) rb_node_base) -
                               offsetof(packed_rect_row_t, rb_node_base_ly));
}

/*
 * Given a row, returns the pointer it should use as the freelist start/end
 * pointers (i.e. what the first element's prev pointer and the last element's
 * end pointer should be).
 */
static packed_rect_el_t* _el_freelist_terminal(const packed_rect_row_t* row) {
  return (packed_rect_el_t*) (((uint8_t*) &row->freelist_start) -
                              offsetof(packed_rect_el_t, next));
}

/*
 * Inserts an empty rectangle after the given element.
 */
static void _el_freelist_insert(packed_rect_el_t* after, packed_rect_el_t* el) {
  el->next = after->next;
  el->prev = after;
  after->next = el;
  el->next->prev = el;
}

/*
 * Removes an empty rectangle from the node's freelist.
 */
static void _el_freelist_remove(packed_rect_el_t* el) {
  packed_rect_el_t* prev = el->prev;
  packed_rect_el_t* next = el->next;

  prev->next = next;
  next->prev = prev;
}

/*
 * Creates a new row object and returns a pointer to it without initializing the
 * rb_node_base or parent_bin pointer elements.
 */
static packed_rect_row_t* _alloc_row(packed_rect_coord_t ly,
                                     packed_rect_coord_t row_w,
                                     packed_rect_coord_t row_h) {
  packed_rect_el_t* empty_el;
  packed_rect_el_t* freelist_terminal;

  packed_rect_row_t* row =
      (packed_rect_row_t*) malloc(sizeof(packed_rect_row_t));
  if (row == NULL) {
    return NULL;
  }

  empty_el = _alloc_empty_el(0, row_w);
  if (empty_el == NULL) {
    free(row);
    return NULL;
  }

  row->ly = ly;
  row->h = row_h;

  rb_init(&row->elements);
  rb_insert_packed_rect_el(&row->elements, &empty_el->rb_node_base);

  // Insert empty_el into the freelist.
  row->freelist_start = empty_el;
  row->freelist_end = empty_el;

  // Point empty_el to the freelist terminal
  freelist_terminal = _el_freelist_terminal(row);
  empty_el->next = freelist_terminal;
  empty_el->prev = freelist_terminal;

  return row;
}

static void _free_row(packed_rect_row_t* row) {
  rb_node_t* node_ptr;
  rb_for_each_mod(&row->elements, node_ptr) {
    packed_rect_el_t* el = _node_base_to_el(node_ptr);
    rb_remove_packed_rect_el(&row->elements, node_ptr);
    packed_rect_el_free(el);
  }
  rb_for_each_mod_fin();

  free(row);
}

/*
 * Removes an element from the row freelist/
 */
static void _row_remove(packed_rect_row_t* row, packed_rect_el_t* el) {
  _el_freelist_remove(el);
  rb_remove_packed_rect_el(&row->elements, &el->rb_node_base);
}

static bool _row_is_empty(const rect_packing_t* packing,
                          const packed_rect_row_t* row) {
  packed_rect_el_t* first_free = row->freelist_start;
  if (first_free == _el_freelist_terminal(row)) {
    return false;
  }
  return first_free->lx == 0 && first_free->w == packing->bin_w;
}

/*
 * Finds the rectangle of smallest width greater or equal to the given width in
 * this row.
 *
 * Returns NULL if no elements in the row have sufficient width.
 */
static packed_rect_el_t* _row_find_fit(const packed_rect_row_t* row,
                                       packed_rect_coord_t w) {
  packed_rect_el_t* freelist_end = _el_freelist_terminal(row);
  for (packed_rect_el_t* el = row->freelist_start; el != freelist_end;
       el = el->next) {
    if (el->w >= w) {
      return el;
    }
  }
  return NULL;
}

static packed_rect_el_t* _split_el(rect_packing_t* packing,
                                   packed_rect_row_t* row, packed_rect_el_t* el,
                                   packed_rect_coord_t w, packed_rect_coord_t h,
                                   bool was_rotated) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
  packed_rect_el_t* new_el;

  packed_rect_el_t* terminal = _el_freelist_terminal(row);
  packed_rect_el_t* first_el = row->freelist_start;
  bool row_was_empty = first_el->next == terminal && first_el->lx == 0 &&
                       first_el->w == packing->bin_w;

  if (el->w == w) {
    _el_freelist_remove(el);
    rb_remove_packed_rect_el(&row->elements, &el->rb_node_base);
    new_el = el;

    new_el->ly = row->ly;
    new_el->h = h;
    new_el->rotated = was_rotated;
    new_el->parent_row = row;
    goto adjust_row;
  }

  new_el = _alloc_el(el->lx, row->ly, w, row->h, was_rotated);
  new_el->ly = row->ly;
  new_el->h = h;
  new_el->parent_row = row;

  el->lx += w;
  el->w -= w;

  // search for where to re-insert the remainder el in the freelist, which
  // is sorted by width:
  packed_rect_el_t* prev = el->prev;
  for (; prev != terminal && prev->w > el->w; prev = prev->prev)
    ;

  _el_freelist_remove(el);
  _el_freelist_insert(prev, el);

  // No need to adjust the position of el in the rb tree, it hasn't
  // shifted laterally, just shrunk.

adjust_row:
  if (row_was_empty) {
    _row_freelist_remove(row);

    if (h < row->h) {
      // split the row
      packed_rect_row_t* split_row =
          _alloc_row(row->ly + h, packing->bin_w, row->h - h);

      packed_rect_bin_t* bin = row->parent_bin;
      split_row->parent_bin = bin;

      // reinsert row into the rows height tree
      row->h = h;
      rb_insert_packed_rect_row_height(&packing->rows_height,
                                       &row->rb_node_base_height);

      // insert the new row into the ly tree and freelist
      _row_freelist_find_pos(packing, split_row);
      rb_insert_packed_rect_row_ly(&bin->rows_ly, &split_row->rb_node_base_ly);
    } else {
      rb_insert_packed_rect_row_height(&packing->rows_height,
                                       &row->rb_node_base_height);
    }
  }

  return new_el;
#pragma GCC diagnostic pop
}

/*
 * Reinserts an element into the freelist of a row, returning the resulting free
 * rect this element merged into (may be the same as el if both of el's
 * neighbors were allocated).
 */
static packed_rect_el_t* _reinsert_el(packed_rect_row_t* row,
                                      packed_rect_el_t* el) {
  // Check in the freelist for el's neighbors, and if they are immediately
  // adjacent, merge them into a single free rect.
  rb_node_t* left_neighbor_node =
      rb_upper_bound_packed_rect_el(&row->elements, &el->rb_node_base);
  rb_node_t* right_neighbor_node =
      rb_lower_bound_packed_rect_el(&row->elements, &el->rb_node_base);
  packed_rect_el_t* left_neighbor = _node_base_to_el(left_neighbor_node);
  packed_rect_el_t* right_neighbor = _node_base_to_el(right_neighbor_node);

  packed_rect_coord_t lx = el->lx;
  packed_rect_coord_t w = el->w;

  if (left_neighbor_node != LEAF &&
      left_neighbor->lx + left_neighbor->w == lx) {
    _el_freelist_remove(left_neighbor);

    w += left_neighbor->w;
    lx = left_neighbor->lx;
    packed_rect_el_free(el);
    el = left_neighbor;
  } else {
    rb_insert_packed_rect_el(&row->elements, &el->rb_node_base);
  }

  if (right_neighbor_node != LEAF && right_neighbor->lx == lx + w) {
    _el_freelist_remove(right_neighbor);
    rb_remove_packed_rect_el(&row->elements, &right_neighbor->rb_node_base);

    w += right_neighbor->w;
    packed_rect_el_free(right_neighbor);
  }

  el->w = w;
  el->lx = lx;

  // find a slot for this new element in the freelist
  packed_rect_el_t* after = row->freelist_end;
  packed_rect_el_t* terminal = _el_freelist_terminal(row);
  for (; after != terminal && after->w > w; after = after->prev)
    ;
  _el_freelist_insert(after, el);

  return el;
}

/**********************************************************
 *                      Bin Helpers                       *
 **********************************************************/

static int _alloc_bin(rect_packing_t* packing) {
  packed_rect_row_t* row;
  packed_rect_bin_t* bin;

  if (vector_size(&packing->bin_list) == packing->max_n_bins) {
    return -1;
  }

  bin = (packed_rect_bin_t*) vector_reserve(&packing->bin_list);
  if (bin == NULL) {
    return -1;
  }

  row = _alloc_row(0, packing->bin_w, packing->bin_h);
  if (row == NULL) {
    vector_pop(&packing->bin_list);
    return -1;
  }

  row->parent_bin = bin;

  rb_init(&bin->rows_ly);

  rb_insert_packed_rect_row_ly(&bin->rows_ly, &row->rb_node_base_ly);

  // insert the row to the end of the row freelist, as it is definitely no
  // smaller than the largest element in there already
  packed_rect_row_t* prev_row = packing->row_freelist_end;
  _row_freelist_insert(prev_row, row);

  return 0;
}

static void _free_bin(packed_rect_bin_t* bin) {
  rb_node_t* node_ptr;
  rb_for_each_mod(&bin->rows_ly, node_ptr) {
    packed_rect_row_t* row = _node_base_ly_to_row(node_ptr);

    rb_remove_packed_rect_row_ly(&bin->rows_ly, node_ptr);

    _free_row(row);
  }
  rb_for_each_mod_fin();
}

static uint32_t _calc_bin_idx(const rect_packing_t* packing,
                              const packed_rect_bin_t* bin) {
  const packed_rect_bin_t* first_el =
      (const packed_rect_bin_t*) vector_get((vector_t*) &packing->bin_list, 0);
  return (uint32_t) (bin - first_el);
}

/*
 * Merges an empty row with its neighbors. Also removes it from the rows_height
 * tree and inserts the resulting row into the row freelist.
 */
static packed_rect_row_t* _merge_empty_row(rect_packing_t* packing,
                                           packed_rect_bin_t* bin,
                                           packed_rect_row_t* row) {
  // Check if row's neighbors are empty, and if they are, merge them together
  // into a single row.
  rb_node_t* down_neighbor_node = rb_find_pred(&row->rb_node_base_ly);
  rb_node_t* up_neighbor_node = rb_find_succ(&row->rb_node_base_ly);

  packed_rect_row_t* down_neighbor = _node_base_ly_to_row(down_neighbor_node);
  packed_rect_row_t* up_neighbor = _node_base_ly_to_row(up_neighbor_node);

  packed_rect_coord_t ly = row->ly;
  packed_rect_coord_t h = row->h;

  // Remove from the rows_height tree, as this row just became empty.
  rb_remove_packed_rect_row_height(&packing->rows_height,
                                   &row->rb_node_base_height);

  if (down_neighbor_node != LEAF && _row_is_empty(packing, down_neighbor)) {
    _row_freelist_remove(down_neighbor);

    rb_remove_packed_rect_row_ly(&bin->rows_ly, &row->rb_node_base_ly);
    _free_row(row);

    h += down_neighbor->h;
    ly = down_neighbor->ly;
    row = down_neighbor;
  }

  if (up_neighbor_node != LEAF && _row_is_empty(packing, up_neighbor)) {
    _row_freelist_remove(up_neighbor);

    rb_remove_packed_rect_row_ly(&bin->rows_ly, &up_neighbor->rb_node_base_ly);

    h += up_neighbor->h;
    _free_row(up_neighbor);
  }

  row->h = h;
  row->ly = ly;

  _row_freelist_find_pos(packing, row);

  return row;
}

/**********************************************************
 *                  Rect Packing Helpers                  *
 **********************************************************/

/*
 * Given the rect_packing struct, returns the pointer it should use as the
 * freelist start/end pointers (i.e. what the first row's prev pointer and the
 * last row's end pointer should be).
 */
static packed_rect_row_t* _row_freelist_terminal(
    const rect_packing_t* packing) {
  return (packed_rect_row_t*) (((uint8_t*) &packing->row_freelist_start) -
                               offsetof(packed_rect_row_t, next));
}

/*
 * Inserts an empty rectangle after the given element.
 */
static void _row_freelist_insert(packed_rect_row_t* after,
                                 packed_rect_row_t* row) {
  row->next = after->next;
  row->prev = after;
  after->next = row;
  row->next->prev = row;
}

static void _row_freelist_find_pos(rect_packing_t* packing,
                                   packed_rect_row_t* row) {
  packed_rect_coord_t h = row->h;
  packed_rect_row_t* after = packing->row_freelist_end;
  packed_rect_row_t* terminal = _row_freelist_terminal(packing);
  for (; after != terminal && after->h > h; after = after->prev)
    ;
  _row_freelist_insert(after, row);
}

/*
 * Removes a row from the freelist.
 */
static void _row_freelist_remove(packed_rect_row_t* row) {
  packed_rect_row_t* prev = row->prev;
  packed_rect_row_t* next = row->next;

  prev->next = next;
  next->prev = prev;
}

/**********************************************************
 *                     Public Methods                     *
 **********************************************************/

int rect_packing_init(rect_packing_t* packing, packed_rect_coord_t bin_w,
                      packed_rect_coord_t bin_h, uint32_t max_n_bins) {
  if (vector_init(&packing->bin_list, sizeof(packed_rect_bin_t), max_n_bins) !=
      0) {
    return -1;
  }

  rb_init(&packing->rows_height);

  packing->max_n_bins = max_n_bins;
  packing->bin_w = bin_w;
  packing->bin_h = bin_h;

  packed_rect_row_t* terminal = _row_freelist_terminal(packing);
  packing->row_freelist_start = terminal;
  packing->row_freelist_end = terminal;

  if (_alloc_bin(packing) != 0) {
    vector_free(&packing->bin_list);
    return -1;
  }

  return 0;
}

void rect_packing_free(rect_packing_t* packing) {
  uint64_t n_bins = vector_size(&packing->bin_list);
  for (uint64_t i = 0; i < n_bins; i++) {
    packed_rect_bin_t* bin =
        (packed_rect_bin_t*) vector_get(&packing->bin_list, i);
    _free_bin(bin);
  }
  vector_free(&packing->bin_list);
}

packed_rect_el_t* rect_packing_insert(rect_packing_t* packing,
                                      packed_rect_coord_t w,
                                      packed_rect_coord_t h) {
  bool rotated;
  if ((rotated = (h < w))) {
    packed_rect_coord_t tmp = w;
    w = h;
    h = tmp;
  }

  packed_rect_row_t* pseudo_row =
      (packed_rect_row_t*) (((uint8_t*) &h) - offsetof(packed_rect_row_t, h));
  rb_node_t* candidate_row_base = rb_lower_bound_packed_rect_row_height(
      &packing->rows_height, &pseudo_row->rb_node_base_height);

  packed_rect_row_t* row = _node_base_height_to_row(candidate_row_base);
  packed_rect_row_t* best_row;
  packed_rect_el_t* best_fit = NULL;
  uint64_t best_loss = 0;

  while (candidate_row_base != LEAF) {
    packed_rect_el_t* el = _row_find_fit(row, w);

    if (el != NULL) {
      // uint64_t el_loss = _calc_el_loss(el->w, row->h, w, h);
      uint64_t el_loss = _calc_el_loss(w, row->h, w, h);
      best_row = row;
      best_fit = el;
      best_loss = el_loss;
      break;
    }

    candidate_row_base = rb_find_succ(candidate_row_base);
    row = _node_base_height_to_row(candidate_row_base);
  }

  // heuristic to determine if we should try placing the rect facing down.
  if (w != h && (best_fit == NULL || best_loss > w * h / 16)) {
    pseudo_row =
        (packed_rect_row_t*) (((uint8_t*) &w) - offsetof(packed_rect_row_t, h));
    candidate_row_base = rb_lower_bound_packed_rect_row_height(
        &packing->rows_height, &pseudo_row->rb_node_base_height);
    row = _node_base_height_to_row(candidate_row_base);

    while (candidate_row_base != LEAF) {
      // If the minimum possible loss of a rect in this row (i.e. a spot
      // that perfectly fits this rectangle width-wise) is greater or
      // equal to the current best_loss, no need to keep searching.
      if (best_fit != NULL && best_loss <= _calc_el_loss(h, row->h, h, w)) {
        break;
      }

      packed_rect_el_t* el = _row_find_fit(row, h);

      if (el != NULL) {
        // uint64_t el_loss = _calc_el_loss(el->h, row->h, h, w);
        uint64_t el_loss = _calc_el_loss(h, row->h, h, w);
        best_row = row;
        best_fit = el;
        best_loss = el_loss;

        // swap w and h
        packed_rect_coord_t tmp = w;
        w = h;
        h = tmp;
        rotated = !rotated;
        break;
      }

      candidate_row_base = rb_find_succ(candidate_row_base);
      row = _node_base_height_to_row(candidate_row_base);
    }
  }

  // heuristic to determine if we should look for an empty row to allocate
  // from
  if (best_fit == NULL || best_loss > w * h / 16) {
    packed_rect_row_t* terminal = _row_freelist_terminal(packing);
    packed_rect_row_t* empty_row = packing->row_freelist_start;
    for (; empty_row != terminal; empty_row = empty_row->next) {
      if (empty_row->h >= h) {
        best_row = empty_row;
        best_fit = empty_row->freelist_start;
        break;
      }
    }
  }

  if (best_fit == NULL) {
    // Allocate a new bin
    if (_alloc_bin(packing) == 0) {
      // The new row is always placed at the end of the row freelist
      best_row = packing->row_freelist_end;
      best_fit = best_row->freelist_start;
    }
  }

  if (best_fit != NULL) {
    packed_rect_el_t* new_el =
        _split_el(packing, best_row, best_fit, w, h, rotated);
    new_el->bin_idx = _calc_bin_idx(packing, best_row->parent_bin);
    return new_el;
  }

  return NULL;
}

void rect_packing_remove(rect_packing_t* packing, packed_rect_el_t* el) {
  packed_rect_row_t* row = el->parent_row;
  packed_rect_bin_t* bin = row->parent_bin;

  el = _reinsert_el(row, el);

  if (el->lx == 0 && el->w == packing->bin_w) {
    // This row is empty
    row = _merge_empty_row(packing, bin, row);

    if (row->ly == 0 && row->h == packing->bin_h) {
      // This bin is now empty, for now do nothing
    }
  }
}

#if defined(DO_TESTING) || defined(DEBUG)

void rect_packing_validate(const rect_packing_t* packing) {
  uint64_t n_rows = 0;
  uint64_t bin_rows = 0;
  uint64_t prev_h = 0;
  rb_node_t* node;
  rb_for_each((rb_tree_t*) &packing->rows_height, node) {
    packed_rect_row_t* row = _node_base_height_to_row(node);

    dbg_assert(!_row_is_empty(packing, row));
    dbg_assert(prev_h <= row->h);
    prev_h = row->h;
    n_rows++;
  }

  prev_h = 0;
  packed_rect_row_t* terminal = _row_freelist_terminal(packing);
  for (packed_rect_row_t* row = packing->row_freelist_start; row != terminal;
       row = row->next) {
    dbg_assert(_row_is_empty(packing, row));
    dbg_assert(prev_h <= row->h);
    prev_h = row->h;
    n_rows++;
  }

  for (uint64_t bin_idx = 0; bin_idx < vector_size(&packing->bin_list);
       bin_idx++) {
    packed_rect_bin_t* bin = (packed_rect_bin_t*) vector_get(
        (vector_t*) &packing->bin_list, bin_idx);
    uint64_t prev_endpos = -1lu;
    bool prev_row_is_empty = false;

    rb_for_each((rb_tree_t*) &bin->rows_ly, node) {
      packed_rect_row_t* row = _node_base_ly_to_row(node);

      dbg_assert((int64_t) prev_endpos <= (int64_t) row->ly);

      if (prev_endpos == row->ly) {
        // There can't be two adjacent free rows, else they should have
        // been merged into one.
        dbg_assert(!_row_is_empty(packing, row) || !prev_row_is_empty);
      }

      rb_node_t* el_node;
      uint64_t n_tree_elements = 0;
      uint64_t prev_el_endpos = -1lu;
      rb_for_each((rb_tree_t*) &row->elements, el_node) {
        packed_rect_el_t* el = _node_base_to_el(el_node);

        dbg_assert((int64_t) el->w > 0);
        dbg_assert((int64_t) prev_el_endpos < (int64_t) el->lx);
        prev_el_endpos = el->lx + el->w;
        n_tree_elements++;
      }

      dbg_assert((int64_t) prev_el_endpos <= (int64_t) packing->bin_w);

      uint64_t n_list_elements = 0;
      uint64_t prev_el_w = 0;
      packed_rect_el_t* el_terminal = _el_freelist_terminal(row);
      for (packed_rect_el_t* el = row->freelist_start; el != el_terminal;
           el = el->next) {
        dbg_assert(((int64_t) el->lx) >= 0);
        dbg_assert(el->w > 0);
        dbg_assert(el->lx + el->w <= packing->bin_w);

        dbg_assert(prev_el_w <= el->w);
        prev_el_w = el->w;
        n_list_elements++;
      }

      dbg_assert(n_tree_elements == n_list_elements);

      prev_endpos = row->ly + row->h;
      prev_row_is_empty = _row_is_empty(packing, row);
      bin_rows++;
    }
  }

  dbg_assert(bin_rows == n_rows);
}

#endif /* defined(DO_TESTING) || defined(DEBUG) */
