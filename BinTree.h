#define BinNodePosi(T) BinNode<T> *
#define stature(p) ((p)?(p)->height:-1)
template <typename T> struct BinNode {
	BinNodePosi(T) parent, lChild, rChild;
	T data; int height; int size();
	BinNodePosi(T) insertAsLC(T const & e) {
		return lChild = new BinNode(e, this);
	};
	BinNodePosi(T) insertAsRC(T const & e) {
		return rChild = new BinNode(e, this);
	};
	BinNodePosi(T) succ() {};
	int size() {
		int s = 1;
		if (lChild) s += lChild->size();
		if (rChild) s += rChild->size();
		return s;
	}


};
template <typename T> class BinTree {
protected:
	int _size;
	BinNodePosi(T) _root;
	virtual int updateHeight(BinNodePosi(T) x) {
		return x->height = 1 + 
			max(stature(x->lChild), stature(x->rChild));
	};
	void updateHeightAbove(BinNodePosi(T) x) {
		while (x)
		{
			updateHeight(x);
			x = x->parent;
		};
	};
public:
	int size() const { return _size; }
	bool empty() const { return !_size; }
	BinNodePosi(T) root() const { return _root; }
	insertAsRC(BinNodePosi(T) x, T const & e) {
		_size++;
		x->insertAsRC(e);
		updateHeightAbove(x);
		return x->rChild;
	}
};

