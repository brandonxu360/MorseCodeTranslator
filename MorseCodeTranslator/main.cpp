/*
* Name: Brandon Xu
* Project: MorseCodeTranslator
* File: main.cpp
* Date: 3/17/23
* Description: Main file for general program flow and execution
*/

#include "bst.hpp"

int main(void) {

	BST<char, std::string> newTree("MorseTable.txt");

	//newTree.recursivePrintInOrder();

	/*char target = 'S';
	BSTNode<char, std::string>* result = newTree.search(target);
	std::cout << *result;*/

	newTree.translate("Convert.txt");

	return 0;
}