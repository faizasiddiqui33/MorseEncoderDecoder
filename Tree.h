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
    Node()
	{
		data = ' ';

		code = "";

		leftSubTree = NULL;

		rightSubTree = NULL;
	}

Node(char data)
	{
		this->data = data;

		code = "";

		leftSubTree = NULL;

		rightSubTree = NULL;
	}

	~Node(){};

void createTree(Node *rootPtr, ifstream &myInputFile)
	{
		char alphabet;

		string start;

		Node *branchPosition = NULL;

		while (!myInputFile.eof())
		{
			myInputFile >> alphabet >> start;

			if (start.at(0) == '.')
			{
				if (rootPtr->leftSubTree == NULL)
				{
					rootPtr->leftSubTree = new Node;
				}
				branchPosition = rootPtr->leftSubTree;
			}
			else if (start.at(0) == '_')
			{
				if (rootPtr->rightSubTree == NULL)
				{
					rootPtr->rightSubTree = new Node;
				}
				branchPosition = rootPtr->rightSubTree;
			}
			for (unsigned int i = 1; i < start.size(); i++)
			{
				if (start.at(i) == '.')
				{
					if (branchPosition->leftSubTree == NULL)
					{
						branchPosition->leftSubTree = new Node;
					}
					branchPosition = branchPosition->leftSubTree;
				}
				else if (start.at(i) == '_')
				{
					if (branchPosition->rightSubTree == NULL)
					{
						branchPosition->rightSubTree = new Node;
					}
					branchPosition = branchPosition->rightSubTree;
				}
			}
			branchPosition->data = alphabet;

			branchPosition->code = start;

			branchPosition = NULL;
		}
	}
    bool findLetter(Node *rootPtr, char lettertoFind)
	{
		Node *branchPosition = NULL;

		bool found = false;

		if (rootPtr->data == lettertoFind)
		{
			cout << rootPtr->code << " ";

			morse_encoded = morse_encoded + rootPtr->code + " ";

			return true;
		}
		else if (rootPtr->data != lettertoFind)
		{
			if (rootPtr->leftSubTree != NULL)
			{
				branchPosition = rootPtr->leftSubTree;

				found = findLetter(branchPosition, lettertoFind);
			}
			if (rootPtr->rightSubTree != NULL && found != true)
			{
				branchPosition = rootPtr->rightSubTree;

				found = findLetter(branchPosition, lettertoFind);
			}
		}
		return found;
	}

};
#endif