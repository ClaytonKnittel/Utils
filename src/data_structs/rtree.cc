
/**********************************************************
 *                       Includes                         *
 **********************************************************/

#include <utils/data_structs/rtree.h>
#include <utils/utils.h>

using namespace Utils;


/**********************************************************
 *                       RTree Class                      *
 **********************************************************/

RTree::RTree(uint32_t m_min, uint32_t m_max) {
	rtree_init(&tree, m_min, m_max);
}

RTree::~RTree() {
	rtree_free(&tree);
}

int RTree::Insert(RTreeEl& el_ptr) {
	return rtree_insert(&this->tree, &el_ptr.el);
}

int RTree::Insert(RTreeEl* el_ptr) {
	return rtree_insert(&this->tree, &el_ptr->el);
}

int RTree::Insert(rtree_el_t* el_ptr) {
	return rtree_insert(&this->tree, el_ptr);
}

int RTree::Delete(RTreeEl& el_ptr) {
	return rtree_delete(&this->tree, &el_ptr.el);
}

int RTree::Delete(RTreeEl* el_ptr) {
	return rtree_delete(&this->tree, &el_ptr->el);
}

int RTree::Delete(rtree_el_t* el_ptr) {
	return rtree_delete(&this->tree, el_ptr);
}

int RTree::Move(RTreeEl& el_ptr, const RTreeRect& new_rect) {
	return rtree_move(&this->tree, &el_ptr.el, &new_rect.rect);
}

int RTree::Move(RTreeEl* el_ptr, const RTreeRect& new_rect) {
	return rtree_move(&this->tree, &el_ptr->el, &new_rect.rect);
}

int RTree::Move(rtree_el_t* el_ptr, const rtree_rect_t* new_rect) {
	return rtree_move(&this->tree, el_ptr, new_rect);
}

RTreeEl& RTree::FindExact(const RTreeRect& rect) const {
	return *reinterpret_cast<RTreeEl*>(FindExact(&rect.rect));
}

rtree_el_t* RTree::FindExact(const rtree_rect_t* rect) const {
	return rtree_find_exact(&this->tree, rect);
}

bool RTree::IntersectsForEach(const rtree_rect_t* rect, rtree_intersects_cb cb,
		void* udata) {
	return rtree_intersects_foreach(&this->tree, rect, cb, udata);
}

#ifdef DO_TESTING

void RTree::Print() const {
	rtree_print(&this->tree);
}

void RTree::Validate() const {
	rtree_validate(&this->tree);
}

#endif /* DO_TESTING */

