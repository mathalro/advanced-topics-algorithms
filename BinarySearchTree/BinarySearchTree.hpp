#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include <iostream>
#include "Node.hpp"

using namespace std;

template <class T>
class BinarySearchTree {
	private:
		Node<T> * insert(Node<T> *node, T item) {
			if (node == NULL) {
				node = new Node<T>;
				node->setItem(item);
			} else if (item < node->getItem()) {
				node->left = insert(node->left, item);
			} else if (item > node->getItem()	){
				node->right = insert(node->right, item);
			} else {
		
			}
			return node;
		}

		bool search(Node<T> *node, T item) {
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

		Node<T> * deletion(Node<T> *node, T item) {
			if (node == NULL) {
				return node;
			} else if (item < node->getItem()) {
				node->left = deletion(node->left, item);
			} else if (item > node->getItem()) {
				node->right = deletion(node->right, item);
			} else {
				if (node->right == NULL) {
					node = node->left;
				} else if (node->left == NULL) {
					node = node->right;
				} else {
					Node<T> * aux = node->left;
					while (aux->right != NULL) aux = aux->right;
					node->setItem(aux->getItem());
					node->left = deletion(node->left, aux->getItem());
				}
			}
			return node;
		}

		void inorderTravessing(Node<T> *node, int deepth) {
			if (node == NULL) return;				
			inorderTravessing(node->left, deepth+1);
			inorderTravessing(node->right, deepth+1);
		}

	public:
		Node<T> *root;
		BinarySearchTree() {
			this->root = NULL;
		}

		void insert(T item) {
			this->root = this->insert(root, item);
		}

		bool search(T item) {
			return this->search(root, item);
		}

		void deletion(T item) {
			this->root = deletion(root, item);
		}

		void inorderTravessing() {
			this->inorderTravessing(root, 0);
		}
};

#endif
