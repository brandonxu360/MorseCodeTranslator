/*
* Name: Brandon Xu
* Project: MorseCodeTranslator
* File: main.cpp
* Date: 3/17/23
* Description: Main file for general program flow and execution
*/

#include "bst.hpp"

int main(void) {

	BST<std::string, std::string> newTree("MorseTable.txt");

	newTree.recursivePrintInOrder();

	return 0;
}