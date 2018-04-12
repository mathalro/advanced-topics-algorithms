#include <iostream>
#include "AVLTree.hpp"
#include "AVLNode.hpp"

using namespace std;

int main () {
	
	AVLTree<int> tree;

	tree.insert(100);
	tree.insert(200);
	tree.insert(50);
	tree.insert(25);
	tree.insert(10);
	tree.insert(75);
	tree.insert(80);
	tree.insert(76);

	tree.inorderTravessing();

	return 0;
}
