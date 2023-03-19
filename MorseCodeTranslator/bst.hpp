/*
* Name: Brandon Xu
* Project: MorseCodeTranslator
* File: bst.hpp
* Date: 3/17/23
* Description: Header file for the bst class, which will contain bstnode objects and organize them in a bst structure
*/

#include "bstnode.hpp"

template <class T, class U> // Types for Keys and values
class BST {

public:

	BST(); // Default constructor - create an empty BST 

	// PRECONDITION: file referenced with fileName is expected to have a specific format: 
	// * one key-value pair per line sepearted by a space (which is the delimiter)
	BST(std::string fileName);

	// PRECONDITION: There are no duplicate keys - all keys are unique and thus must be greater than or less than each other, never equal
	// NOTE: BST structure is dictated by the keys, not the values (ie. left children are less than and right children and greater than)
	void insert(BSTNode<T, U>* pNewNode);

	// Wrapper method to print tree in order (left-most printed first)
	void recursivePrintInOrder();

	// Recursive step to be used in recursivePrintInOrder method
	void recursivePrintStep(BSTNode<T, U>* pCurrNode);

private:

	BSTNode<T, U>* _rootNode; // Root node 

};

// Default constructor - create an empty BST 
template <class T, class U>
BST<T, U>::BST() {
	_rootNode = nullptr;
}

// PRECONDITION: file referenced with fileName is expected to have a specific format: 
// * one key-value pair per line sepearted by a space (which is the delimiter)
template <class T, class U>
BST<T, U>::BST(std::string fileName) { // Constructor that builds a BST object based on key-value pairs read from the inputted file name

	   // Open file for read
	std::ifstream file(fileName);

	std::string currLine; // Iterator string to hold current line
	std::string newKey, newVal; // Variables to hold tokenized keys and values from line

	// Iterate through every line of file, tokenizing keys and values
	while (getline(file, newKey, ' ')) { // Get key and store in newKey

		getline(file, newVal); // Get value and store in newVal

		BSTNode<T, U>* pNewNode = new BSTNode<T, U>(newKey, newVal); // Create a new BSTNode with the key-value pair

		insert(pNewNode); // Insert each key-value pair as BSTNode into the BST
	}


	// Close file
	file.close();
}

// PRECONDITION: There are no duplicate keys - all keys are unique and thus must be greater than or less than each other, never equal
// NOTE: BST structure is dictated by the keys, not the values (ie. left children are less than and right children and greater than)
template <class T, class U>
void BST<T, U>::insert(BSTNode<T, U>* pNewNode) { // Insert a new node containing newKey and NewVal

	bool done = false; // Flag to indicate when node has found its final position
	BSTNode<T, U>* pCurrNode = _rootNode; // Iterator node - initially set to root node

	if (pCurrNode == nullptr) {  // Tree is empty
		_rootNode = pNewNode;
		done = true;
	}

	else { // Tree is not empty
		while (!done) {

			if (pNewNode->getKey() < pCurrNode->getKey()) { // Look at left child spot since newNode is less than currNode

				if (pCurrNode->getPLeftChild() == nullptr) { // Left child is empty, this is where newNode should be inserted
					pCurrNode->setPLeftChild(pNewNode);
					done = true;
				}

				else pCurrNode = pCurrNode->getPLeftChild(); // Move onto next node (left child) for next comparison 

			}

			else if (pNewNode->getKey() > pCurrNode->getKey()) { // Look at right child spot since newNode is greater than currNode

				if (pCurrNode->getPRightChild() == nullptr) { // Right child is empty, this is where newNode should be inserted
					pCurrNode->setPRightChild(pNewNode);
					done = true;
				}

				else pCurrNode = pCurrNode->getPRightChild(); // Move onto next node (right child) for next comparison 

			}
		}
	}
}

// Wrapper method to print tree in order (left-most printed first)
template <class T, class U>
void BST<T, U>::recursivePrintInOrder() {
	recursivePrintStep(_rootNode);
}

// Print tree in order (left-most printed first) using recursion
template <class T, class U>
void BST<T, U>::recursivePrintStep(BSTNode<T, U>* pCurrNode) {

	if (pCurrNode->getPLeftChild() != nullptr) { // // Left child: EXISTS, regardless of state of right child
		recursivePrintStep(pCurrNode->getPLeftChild()); // Move to that left child node
	}

	std::cout << *pCurrNode;

	if (pCurrNode->getPRightChild() != nullptr) { // Right child: EXISTS, left child: DOES NOT EXIST
		recursivePrintStep(pCurrNode->getPRightChild()); // Move to right child node
	}
}


