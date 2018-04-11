#include <iostream>
#include "Node.hpp"
#include "BinarySearchTree.hpp"
#include <vector>

using namespace std;

int main () {
	BinarySearchTree<int> tree;
	
	tree.insert(10);
	tree.insert(15);
	tree.insert(5);
	tree.insert(10);
	tree.insert(2);
	tree.insert(20);
	tree.insert(3);
	tree.insert(18);

	tree.inorderTravessing();

	while (tree.root != NULL) {
		tree.deletion(tree.root->getItem());
		cout << endl;
		tree.inorderTravessing();
	}

	return 0;
}
