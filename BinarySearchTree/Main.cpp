#include <iostream>
#include "Node.hpp"
#include "BinarySearchTree.hpp"
#include <vector>

using namespace std;

int main () {
	BinarySearchTree<int> tree;

	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	tree.insert(6);
	tree.insert(7);
	tree.insert(8);
	tree.insert(9);
	tree.insert(10);

	tree.inorderTravessing();

	return 0;
}
