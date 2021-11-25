///@file tree.h
#ifndef TREE_H
#define TREE_H

/// This header file includes all standard libraries
#include <bits/stdc++.h>

/// tells the compiler to make all the names in the predefined standard library available to our program
using namespace std;
class Node
{
public:
	char data;

	string code;

	string morse_encoded = "", morse_decoded = "";

	Node *leftSubTree;

	Node *rightSubTree;
};
#endif