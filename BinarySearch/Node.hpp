#ifndef NODE_HPP
#define NODE_HPP

template <class T>
class Node {
	private:
		T item;

	public:
		Node<T> *left, *right;

		Node() {
			this->left = NULL;
			this->right = NULL;
		}

		void setItem(T item) {
			this->item = item;
		}

		T getItem() {
			return this->item;	
		}
};

#endif
