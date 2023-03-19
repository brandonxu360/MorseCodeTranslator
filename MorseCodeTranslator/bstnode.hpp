/*
* Name: Brandon Xu
* Project: MorseCodeTranslator
* File: bstnode.hpp
* Date: 3/17/23
* Description: Header file for the bstnode class, which will represent the individual nodes in a bst
*/

#include "header.hpp"

template <class T, class U> // Types for Keys and values
class BSTNode {

public:

	BSTNode();
	
	BSTNode(T newKey, U newVal);

	// Getter for key 
	T getKey();

	// Getter for value
	U getValue();

	// Getter for pointer to right child node
	BSTNode* getPRightChild();

	// Getter for pointer to left child node
	BSTNode* getPLeftChild();

	// Setter for pointer to right child node
	void setPRightChild(BSTNode* node);

	// Setter for pointer to left child node
	void setPLeftChild(BSTNode* node);

// Member attributes
private:

	// Key-value pair
	T _key;
	U _value;

	// Pointers to child nodes
	BSTNode* _pRight;
	BSTNode* _pLeft;

};

template <class T, class U>
BSTNode<T, U>::BSTNode() { // Default constructor

	// Initialize child pointers to null
	_pLeft = nullptr;
	_pRight = nullptr;

}

template <class T, class U>
BSTNode<T, U>::BSTNode(T newKey, U newVal) { // Constructor for existing key-value pair

		// Initialize child pointers to null
	_pLeft = nullptr;
	_pRight = nullptr;

	// Assign given key-value pair
	_key = newKey;
	_value = newVal;

}

// Getter for key 
template <class T, class U>
T BSTNode<T, U>::getKey() {
	return _key;
}

// Getter for value
template <class T, class U>
U BSTNode<T, U>::getValue() {
	return _value;
}

// Getter for pointer to right child node
template <class T, class U>
BSTNode<T, U>* BSTNode<T, U>::getPRightChild() {
	return _pRight;
}

// Getter for pointer to left child node
template <class T, class U>
BSTNode<T, U>* BSTNode<T, U>::getPLeftChild() {
	return _pLeft;
}

// Setter for pointer to right child node
template <class T, class U>
void BSTNode<T, U>::setPRightChild(BSTNode* node) {
	_pRight = node;
}

// Setter for pointer to left child node
template <class T, class U>
void BSTNode<T, U>::setPLeftChild(BSTNode* node) {
	_pLeft = node;
}

// Overloaded stream insertion operator for displaying a BSTNode object
// Format: [Key: ___, Value: ___]
template <class T, class U>
std::ostream& operator<<(std::ostream& os, BSTNode<T, U>& node) {
	os << "[Key: " << node.getKey() << ", Value: " << node.getValue() << "]" << std::endl;
	return os;
}