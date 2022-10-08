#ifndef _R_TREE_H_
#define _R_TREE_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus

#include <memory>
#include <type_traits>

extern "C" {
#endif /* __cplusplus */

/*
 * Implementation file of R* trees for storage of rectangular elements
 */

typedef int64_t rtree_coord_t;

// the default fraction of m_max that p is set to (the number of nodes to
// reinsert)
#define DEFAULT_REINSERT_P_PCT .30f

typedef struct rtree_rect {
  rtree_coord_t lx;
  rtree_coord_t ly;
  rtree_coord_t ux;
  rtree_coord_t uy;
} rtree_rect_t;

/*
 * the base struct that all nodes have in common
 */
typedef struct rtree_node_base {
  // the bounding box of the node
  rtree_rect_t bb;

  struct rtree_node* parent;

  // the number of children of this node
  uint32_t n;
  // the index of this node in parent's elements list
  uint32_t parent_idx;
} rtree_node_base_t;

/*
 * rtree_nodes are internal nodes in an rtree
 */
typedef struct rtree_node {
  rtree_node_base_t base;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
  // the list of children of this node
  rtree_node_base_t* children[];
#pragma GCC diagnostic pop
} rtree_node_t;

// forward declare for rtree_el
typedef struct rtree_leaf rtree_leaf_t;

/*
 * the base element stored in the rtree, which consists of a bounding box and a
 * pointer to the element's parent
 */
typedef struct rtree_el {
  rtree_rect_t bb;
  rtree_leaf_t* parent;
  // the index of this node in parent's elements list
  uint32_t parent_idx;
} rtree_el_t;

/*
 * rtree_leaf's are leaf nodes in an rtree
 */
typedef struct rtree_leaf {
  rtree_node_base_t base;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
  // the list of elements of this node
  rtree_el_t* elements[];
#pragma GCC diagnostic pop
} rtree_leaf_t;

typedef struct rtree {
  rtree_node_base_t* root;
  // min number of children a node can have
  uint32_t m_min;
  // max number of children a node can have
  uint32_t m_max;

  // the number of elements to reinsert when a node overflows
  uint32_t reinsert_p;

  // the depth of the tree (i.e. number of ancestors the leaves have)
  uint64_t depth;
} rtree_t;

rtree_coord_t rtree_rect_area(const rtree_rect_t* r);

rtree_coord_t rtree_rect_margin(const rtree_rect_t* r);

bool rtree_rect_eq(const rtree_rect_t* a, const rtree_rect_t* b);

bool rtree_rect_intersects(const rtree_rect_t* a, const rtree_rect_t* b);

/*
 * returns true if p contains r (borders may intersect), false otherwise
 */
bool rtree_rect_contains(const rtree_rect_t* p, const rtree_rect_t* r);

rtree_coord_t rtree_rect_overlap(const rtree_rect_t* a_ptr,
                                 const rtree_rect_t* b_ptr);

/*
 * returns the amount of area increase that would be required to accomodate rect
 */
rtree_coord_t rtree_rect_area_increase(const rtree_rect_t* base,
                                       const rtree_rect_t* rect);

/*
 * extends base to accomodate rect, returning the amount of area increase that
 * would be required to accomodate rect
 */
rtree_coord_t rtree_rect_combine(rtree_rect_t* dst, const rtree_rect_t* base,
                                 const rtree_rect_t* rect);

/*
 * extends base to accomodate rect, returning the amount of area increase that
 * would be required to accomodate rect
 */
rtree_coord_t rtree_rect_extend(rtree_rect_t* base, const rtree_rect_t* rect);

/*
 * Callback method signature for iterating over all elements of an rtree.
 *
 * If this callback returns false, iteration is stopped.
 */
typedef bool (*rtree_foreach_cb)(const rtree_el_t* el, void* udata,
                                 const rtree_t* tree);

/*
 * Callback method signature for find-all-intersecting methods. The current
 * intersecting rect in the rtree is passed via el.
 *
 * If this callback returns false, iteration is stopped, otherwise continuing
 * until all intersecting rectangles have been found.
 */
typedef bool (*rtree_intersects_cb)(const rtree_el_t* el, void* udata,
                                    const rtree_rect_t* rect,
                                    const rtree_t* tree);

int rtree_init(rtree_t*, uint32_t m_min, uint32_t m_max);
void rtree_free(rtree_t*);

int rtree_insert(rtree_t*, rtree_el_t* el_ptr);

/*
 * Removes the rtree_el from the tree.
 */
int rtree_delete(rtree_t*, rtree_el_t*);

/*
 * Iterates over all elements of the rtree.
 *
 * Concurrent modification of the tree results in undefined behavior.
 *
 * Returns true if the iteration completed successfully, or false if iteration
 * was interrupted.
 */
bool rtree_foreach(const rtree_t*, rtree_foreach_cb callback, void* udata);

/*
 * Finds the rtree node with rectangle exactly matching that of the rectangle
 * passed. Will only return one rectangle if multiple matches exist in the tree.
 */
rtree_el_t* rtree_find_exact(const rtree_t*, const rtree_rect_t* rect);

/*
 * Iterates over every element in the tree that intersects with the given
 * rectangle, calling callback on each instance.
 *
 * Returns true if the iteration completed successfully, or false if iteration
 * was interrupted.
 */
bool rtree_intersects_foreach(const rtree_t*, const rtree_rect_t* rect,
                              rtree_intersects_cb callback, void* udata);

/*
 * Updates the rtree_el's bounding box to the supplied new bounding box. This
 * method is most efficient when the bounding box changes only slightly.
 */
int rtree_move(rtree_t*, rtree_el_t*, const rtree_rect_t* new_rect);

#ifdef DO_TESTING
void rtree_print(const rtree_t*);

void rtree_validate(const rtree_t*);
#endif /* DO_TESTING */

#ifdef __cplusplus
}

namespace Utils {

class RTreeRect {
  friend class RTree;
  friend class RTreeEl;

 private:
  rtree_rect_t rect;

 public:
  explicit RTreeRect(rtree_coord_t lx, rtree_coord_t ly, rtree_coord_t ux,
                     rtree_coord_t uy)
      : rect({ lx, ly, ux, uy }) {}
  explicit RTreeRect(const rtree_rect_t& rect)
      : rect({ rect.lx, rect.ly, rect.ux, rect.uy }) {}
  virtual ~RTreeRect() {}

  rtree_coord_t lx() const {
    return rect.lx;
  }

  rtree_coord_t ly() const {
    return rect.ly;
  }

  rtree_coord_t ux() const {
    return rect.ux;
  }

  rtree_coord_t uy() const {
    return rect.uy;
  }
};

class RTreeEl {
  friend class RTree;

 public:
  rtree_el_t el;

  RTreeEl() {}

 public:
  RTreeEl(const RTreeRect& rect) {
    el.bb = rect.rect;
  }
  virtual ~RTreeEl() {}

  RTreeRect GetBB() const {
    return RTreeRect(el.bb);
  }
};

class RTree {
 private:
  rtree_t tree;

  template <typename IntersectsCB>
  bool _IntersectsLeaf(const rtree_leaf_t* leaf, const rtree_rect_t* rect,
                       IntersectsCB callback) const {
    const RTreeEl tmp;
    const size_t el_offset = size_t(&tmp.el) - size_t(&tmp);

    for (uint32_t i = 0; i < leaf->base.n; i++) {
      if (rtree_rect_intersects(&leaf->elements[i]->bb, rect)) {
        uint8_t* el_ptr = reinterpret_cast<uint8_t*>(leaf->elements[i]);
        if (!callback(
                std::ref(*reinterpret_cast<RTreeEl*>(el_ptr - el_offset)))) {
          return false;
        }
      }
    }

    return true;
  }

  template <typename IntersectsCB>
  bool _Intersects(const rtree_node_t* node, const rtree_rect_t* rect,
                   IntersectsCB callback, int depth) const {
    for (uint32_t i = 0; i < node->base.n; i++) {
      if (!rtree_rect_intersects(&node->children[i]->bb, rect)) {
        continue;
      }

      if (depth == 0) {
        if (!_IntersectsLeaf((const rtree_leaf_t*) node->children[i], rect,
                             callback)) {
          return false;
        }
      } else {
        if (!_Intersects((const rtree_node_t*) node->children[i], rect,
                         callback, depth - 1)) {
          return false;
        }
      }
    }

    return true;
  }

 public:
  RTree(uint32_t m_min, uint32_t m_max);
  virtual ~RTree();

  int Insert(RTreeEl&);
  int Insert(RTreeEl*);
  int Insert(rtree_el_t*);

  int Delete(RTreeEl&);
  int Delete(RTreeEl*);
  int Delete(rtree_el_t*);

  int Move(RTreeEl&, const RTreeRect& new_rect);
  int Move(RTreeEl*, const RTreeRect& new_rect);
  int Move(rtree_el_t*, const rtree_rect_t* new_rect);

  template <typename ForEachCB>
  bool ForEach(ForEachCB callback) const {
    const RTreeEl tmp;
    const size_t el_offset = size_t(&tmp.el) - size_t(&tmp);

    uint64_t depth = tree.depth;
    const rtree_node_base_t* node = tree.root;
    uint32_t i = 0;
    uint32_t n = node->n;

    if (node == NULL) {
      return true;
    }

    while (true) {
      if (i == n) {
ascent_parent:
        i = node->parent_idx + 1;
        node = &node->parent->base;

        if (node == NULL) {
          return true;
        }

        n = node->n;
        depth++;
        continue;
      }

      if (depth > 0) {
        const rtree_node_t* inner_node = (rtree_node_t*) node;
        node = inner_node->children[i];
        i = 0;
        n = node->n;
        depth--;
        continue;
      }

      const rtree_leaf_t* leaf = (rtree_leaf_t*) node;
      for (; i < n; i++) {
        uint8_t* el_ptr = reinterpret_cast<uint8_t*>(leaf->elements[i]);
        if (!callback(
                std::ref(*reinterpret_cast<RTreeEl*>(el_ptr - el_offset)))) {
          // stop iteration.
          return false;
        }
      }
      goto ascent_parent;
    }

    return true;
  }

  RTreeEl& FindExact(const RTreeRect&) const;
  rtree_el_t* FindExact(const rtree_rect_t*) const;

  template <typename IntersectsCB>
  bool IntersectsForEach(const RTreeRect& rect, IntersectsCB callback) const {
    rtree_node_base_t* n = tree.root;
    uint64_t depth = tree.depth;

    if (depth > 0) {
      return _Intersects((const rtree_node_t*) n, &rect.rect, callback,
                         depth - 1);
    } else {
      return _IntersectsLeaf((const rtree_leaf_t*) n, &rect.rect, callback);
    }
  }
  bool IntersectsForEach(const rtree_rect_t*, rtree_intersects_cb cb,
                         void* udata);

#ifdef DO_TESTING
  void Print() const;
  void Validate() const;
#endif /* DO_TESTING */
};

} /* namespace Utils */

#endif /* __cplusplus */

#endif /* _R_TREE_H_ */
