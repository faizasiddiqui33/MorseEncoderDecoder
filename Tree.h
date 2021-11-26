/*****************************************************************************************************************************
	* @file		Tree.h
    * @brief	Module Name is Tree Header File
    * @author	Faiza Fatma Siddiqui, StudentID: 200473896
    * @date		25-11-2021 (Created & Modified)
    * @details 	This header file has a class which includes:
	* 	- A default & parametrized constructor to initialize values 
	*	- User-defined functions to create a binary tree, find a letter from the binary tree, 
	*	  find a morse code from the letter in the binary tree, encode a message received from the main function, 
	*	  decode a message from morse code
    * Purpose:	To perform all the tree functions: Creating, Inserting nodes, Finding nodes, Encoding, Decoding
	* Method Output: Tree is created, message is encoded & decoded in morse code & returned to the main function
	* @pre		Use only alphabets to encode, not numbers or symbols
    * @bug		No known bugs
	* @warning	Improper use can crash the program while taking input from the user
*****************************************************************************************************************************/
///@file tree.h

#ifndef TREE_H
#define TREE_H

/// This header file includes all standard libraries
#include <bits/stdc++.h>

/// tells the compiler to make all the names in the predefined standard library available to our program
using namespace std;
/*****************************************************************************************************************************
	* @brief	Module Name is Node Class 
    * @author	Faiza Fatma Siddiqui, StudentID: 200473896
    * @date		25-11-2021 (Created & Modified)
    * @details 	This class is used to define functions that perform the following operations related to binary tree:
	* Description: 
	*	- Creating a binary tree using pre-order to input alphabets
	*	- Finding a letter from the binary tree
	*	- Finding a morse code from the letter in the binary tree
	*	- Encoding a message received from the main function in morse code using the binary tree
	*	- Decoding a message from morse code using the binary tree
    * Purpose:	CS 700 - Software Development Fundamentals - Assignment 5
	* Method Output: A message received from main function is encoded in morse code, then decoded to original message
    * @bug		No known bugs
*****************************************************************************************************************************/
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
	bool findCode(Node *rootPtr, string code)
	{
		Node *branchPosition = NULL;

		bool found = false;

		if (rootPtr->code == code)
		{
			morse_decoded = morse_decoded + rootPtr->data + " ";

			return true;
		}
		else if (rootPtr->code != code)
		{
			if (rootPtr->leftSubTree != NULL)
			{
				branchPosition = rootPtr->leftSubTree;

				found = findCode(branchPosition, code);
			}
			if (rootPtr->rightSubTree != NULL && found != true)
			{
				branchPosition = rootPtr->rightSubTree;

				found = findCode(branchPosition, code);
			}
		}
		return found;
	}

	void encode(Node *rootPtr, string message)
	{
		char lettertoFind;

		std::replace(message.begin(), message.end(), '/', ' ');

		cout << " in morse code: ";

		for (unsigned int i = 0; i < message.size(); i++)
		{
			lettertoFind = message.at(i);

			findLetter(rootPtr, lettertoFind);
		}
		cout << endl << endl;
	}
    void decode(Node *rootPtr, string morsecodeEncoded)
	{
		string morsecode;

		std::replace(morsecodeEncoded.begin(), morsecodeEncoded.end(), '/', ' ');

		for (unsigned int i = 0; i < morsecodeEncoded.size(); i++)
		{
			if (morsecodeEncoded.at(i) == ' ')
			{
				findCode(rootPtr, morsecode);
			}
			else
			{
				morsecode += morsecodeEncoded.at(i);
			}
		}
		findCode(rootPtr, morsecode);

		cout << "Decoded Message: " << morsecodeEncoded << endl;
	}
};
#endif