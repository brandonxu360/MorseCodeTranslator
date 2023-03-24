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

	// Destructor
	~BST(); 

	// Recursive delete node step used in destructor
	void recursiveDeleteStep(BSTNode<T, U>* node);

	// PRECONDITION: There are no duplicate keys - all keys are unique and thus must be greater than or less than each other, never equal
	// NOTE: BST structure is dictated by the keys, not the values (ie. left children are less than and right children and greater than)
	void insert(BSTNode<T, U>* pNewNode);

	// Wrapper method to print tree in order (left-most printed first)
	void recursivePrintInOrder();

	// Recursive step to be used in recursivePrintInOrder method
	void recursivePrintStep(BSTNode<T, U>* pCurrNode);

	// Recursive step for printTreeStructure method
	void recursiveTreePrintStep(BSTNode<T, U>* pCurrNode, int level);
	
	// Print full binary tree structure
	void printTreeStructure();

	// Search for a node in the BST containing the target (of type T) and return a pointer to that node
	BSTNode<T, U>* search(T& target);

	// NOTE: not sure if this is the right place for this function
	// Use the BST to translate characters in a file (file name given) and print result to console
	void translate(std::string fileName);

	// NOTE: not sure if this is the right place for this function
	void lowerToUpperCase(std::string& inputStr);

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
// NOTE: this constructor is made to create BSTs with BSTNodes of type char for key and std::string for value
template <class T, class U>
BST<T, U>::BST(std::string fileName) { // Constructor that builds a BST object based on key-value pairs read from the inputted file name

	_rootNode = nullptr; // Initialize member attribute

	// Open file for read
	std::ifstream file(fileName);

	std::string newKey, newVal; // Variables to hold tokenized keys and values from line

	// Iterate through every line of file, tokenizing keys and values
	while (getline(file, newKey, ' ')) { // Get key and store in newKey

		getline(file, newVal); // Get value and store in newVal

		BSTNode<T, U>* pNewNode = new BSTNode<T, U>(newKey[0], newVal); // Create a new BSTNode with the key-value pair

		insert(pNewNode); // Insert each key-value pair as BSTNode into the BST
	}


	// Close file
	file.close();
}

// Destructor
template <class T, class U>
BST<T, U>::~BST() {
	if (_rootNode != nullptr) recursiveDeleteStep(_rootNode);
}

// Recursive delete node step used in the destructor
template <class T, class U>
void BST<T, U>::recursiveDeleteStep(BSTNode<T, U>* node) {

	// Use post-order traversal to delete nodes bottom up (children first, then parent)
	if (node->getPLeftChild() != nullptr) recursiveDeleteStep(node->getPLeftChild());
	if (node->getPRightChild() != nullptr) recursiveDeleteStep(node->getPRightChild());
	std::cout << "Deleting node containing key: " << node->getKey() << std::endl;
	delete node;
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

// Print full tree in binary stree structure
template <class T, class U>
void BST<T, U>::printTreeStructure() {
	recursiveTreePrintStep(_rootNode, 0);
}

// Recursive step for printTreeStructure method
template <class T, class U>
void BST<T, U>::recursiveTreePrintStep(BSTNode<T, U>* pCurrNode, int level) {

	if (pCurrNode == nullptr) return; // Exit step if current node is null

	recursiveTreePrintStep(pCurrNode->getPRightChild(), level + 1); // Print right subtree/node first

	// Print current node in the middle of the right and left subtrees/nodes
	for (int i = 0; i < level; i++) { // Apply increment depending on level
		std::cout << "   |  ";
	}
	std::cout << pCurrNode->getKey() << std::endl; // Print current node after proper indentation

	recursiveTreePrintStep(pCurrNode->getPLeftChild(), level + 1); // Print left subtree/node
	
}

// Search for a node in the BST containing the target (of type T) and return a pointer to that node (nullptr if not found)
template<class T, class U>
BSTNode<T, U>* BST<T, U>::search(T& target) {
	
	bool found = false; // Flag for if the target node was found
	BSTNode<T, U>* pCurrNode = _rootNode; // Iterator node initially set to root

	while (!found) {

		if (pCurrNode == nullptr) return nullptr; // Target was not found

		// Check the current node for a match, return if true
		else if (target == pCurrNode->getKey()) return pCurrNode;

		// Move to right child if target is greater than current node
		else if (target > pCurrNode->getKey()) pCurrNode = pCurrNode->getPRightChild();

		// Move to left child if target is less than current node
		else if (target < pCurrNode->getKey()) pCurrNode = pCurrNode->getPLeftChild();
	}
}

// Translation function - takes file name, converts the characters inside the file to morse, and print the result to console
template<class T, class U>
void BST<T, U>::translate(std::string fileName) {

	// Open file for read
	std::ifstream file(fileName);

	std::string currLine; // Iterator string to hold current line

	// Iterate through every line of file, tokenizing keys and values
	while (getline(file, currLine)) { // Get key and store in newKey

		lowerToUpperCase(currLine); // Convert any lowercase to uppercase
		
		for (int i = 0; i < currLine.length(); i++) { // Convert each character

			BSTNode<T, U>* node = search(currLine[i]);
			if (node != nullptr) { // Check that the character is found (spaces will return null)
				std::cout << node->getValue() << "   ";
			}

		}

		std::cout << std::endl; // New line for each line retrieved from file

	}


	// Close file
	file.close();
}

// Helper function that accepts a string and converts the lowercase letters to uppercase
template<class T, class U>
void BST<T, U>::lowerToUpperCase(std::string& inputStr) {
	
	for (int i = 0; i < inputStr.length(); i++) { // Iterate through each character of the string
	
		inputStr[i] = toupper(inputStr[i]);

	}
}

