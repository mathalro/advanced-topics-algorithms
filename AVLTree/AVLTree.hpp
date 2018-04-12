#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <iostream>
#include "AVLNode.hpp"

#define Node AVLNode<T>

using namespace std;

template <class T>

class AVLTree {
	private:
		Node *root;

		int height(Node *node) {
			if (node == NULL) return 0;
			return node->getH();
		}

		Node * leftRotation(Node *node) {
			//cout << "Left Rotation" << endl;
			Node *left = node->left;
			Node *leftRight = left->right;

			left->right = node;
			node->left = leftRight;

			node->setH(max(height(node->left), height(node->left)) + 1);
			left->setH(max(height(left->left), height(left->right)) + 1);

			return left;
		}
	
		Node * rightRotation(Node *node) {
			//cout << "Right Rotation" << endl;
			Node *right = node->right;
			Node *rightLeft = right->left;
			
			int tmpH = node->getH();
			node->setH(right->getH());
			right->setH(tmpH);

			right->left = node;
			node->right = rightLeft;
		
			node->setH(max(height(node->left), height(node->left)) + 1);
			right->setH(max(height(right->left), height(right->right)) + 1);

			return right;
		}

		Node * insert(Node *node, T item) {
			if (node == NULL) {
				node = new Node;
				node->setItem(item);
				node->setH(1);
			} else if (item < node->getItem()) {
				node->left = insert(node->left, item);
				int leftH = node->left->getH(), rightH = 0;
				if (node->right != NULL) rightH = node->right->getH();

				node->setH(max(leftH, rightH)+1);
				// left is too heavy
				if (leftH - rightH > 1) {					
					int leftLeftH = 0, leftRightH = 0;
					if (node->left->left != NULL) leftLeftH = node->left->left->getH();
					if (node->left->right != NULL) leftRightH = node->left->right->getH();
					if (leftLeftH > leftRightH) {
						// case 1 - left left
						return leftRotation(node);
					} else {
						// case 2 - left right
						node->left = rightRotation(node->left);
						return leftRotation(node);
					}
				}
			} else if (item > node->getItem()	){
				node->right = insert(node->right, item);
				node->setH(node->getH()+1);
				int rightH = node->right->getH(), leftH = 0;
				if (node->left != NULL) leftH = node->left->getH();

				node->setH(max(leftH, rightH)+1);
				// right is too heavy
				if (rightH - leftH > 1) {					
					int rightRightH = 0, rightLeftH = 0;
					if (node->right->right != NULL) rightRightH = node->right->right->getH();
					if (node->right->left != NULL) rightLeftH = node->right->left->getH();
					if (rightRightH > rightLeftH) {
						// case 1 - right right
						return rightRotation(node);
					} else {
						// case 2 - right left
						node->right = leftRotation(node->right);
						return rightRotation(node);
					}
				}
			} else {

			}
			return node;
		}

		bool search(Node *node, T item) {
			if (node == NULL) {
				return false;
			} else if (item < node->getItem()) {
				return search(node->left, item);
			} else if (item > node->getItem()) {
				return search(node->right, item);
			} else {
				return true;
			}
		}

		void inorderTravessing(Node *node) {
			if (node == NULL) return;				
			inorderTravessing(node->left);
			for (int i = 0; i < root->getH() - node->getH(); i++) cout << "    ";
			cout << node->getItem() << endl;
			inorderTravessing(node->right);
		}

	public:

		bool search(T item) {
			return this->search(root, item);
		}

		void insert(T item) {
			//cout << item << endl;
			root = this->insert(root, item);
		}

		void inorderTravessing() {
			this->inorderTravessing(root);
		}
};

#endif
