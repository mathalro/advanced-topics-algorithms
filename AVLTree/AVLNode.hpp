#ifndef AVLNODE_HPP
#define AVLNODE_HPP

template <class T>
class AVLNode {
	private:
		T item;
		int h;
	public:
		AVLNode<T> *left, *right;
		
		AVLNode() {
			this->left = NULL;
			this->right = NULL;
		}

		void setItem(T item) {
			this->item = item;
		}

		T getItem() {
			return this->item;
		}

		void setH(int h) {
			this->h = h;
		}

		int getH() {
			return this->h;
		}
};

#endif
