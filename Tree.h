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
	///data stores the letter of the node
	char data;

	///to store the coded message which is being passed
	string code;

	///to setting the encoded morse code and decoded message to blank
	string morse_encoded = "", morse_decoded = "";

	///pointer to left subtree, to search letters or insert nodes
	Node *leftSubTree;

	///pointer to right subtree, to search letters or insert nodes
	Node *rightSubTree;

	/*****************************************************************************************************************************
	* @brief	Module Name is Node Class Default Constructor
    * @author	Faiza Fatma Siddiqui, StudentID: 200473896
    * @date		25-11-2021 (Created & Modified)
    * @details 	This class is used to define functions that perform the following operations related to binary tree:
	* Description: Node Default Constructor that intializes members for setting the values of data fields
	*	- Creating a binary tree using pre-order to input alphabets
	*	- Finding a letter from the binary tree
	*	- Finding a morse code from the letter in the binary tree
	*	- Encoding a message received from the main function in morse code using the binary tree
	*	- Decoding a message from morse code using the binary tree
    * Purpose:	CS 700 - Software Development Fundamentals - Assignment 5
	* Method Output: A message received from main function is encoded in morse code, then decoded to original message
	* @param	None
    * @return	integer - 0 if program executed successfully, else nonzero will be returned
	* @pre	Precondition: Message entered by the user should not have numbers or symbols. Alphabets only
	* @post	Postcondition: Gives the encoded and decoded message
	* Method Output: 
	* Asks the user to input a message to encode
	* Encodes the message in Morse Code
	* Decodes and prints the original message from Morse Code 
    * @bug		No known bugs
*****************************************************************************************************************************/
	Node()
	{
		/// initializing the data of every node as ' ' so it does not display any other garbage data
		data = ' ';

		/// initializing the code as '' so it does not display any other garbage data
		code = "";

		///initially storing the left subtree to Null, since we have not inserted anything yet
		leftSubTree = NULL;

		///initially storing the right subtree to Null, since we have not inserted anything yet
		rightSubTree = NULL;
	}
	/*****************************************************************************************************************************
	* @brief	Module Name is Node Class Parametrized Constructor
    * @author	Faiza Fatma Siddiqui, StudentID: 200473896
    * @date		25-11-2021 (Created & Modified)
    * @details 	Purpose of this constructor is to initialize a node that is created with its data i.e. alphabet with some values
	* Description: Node Parametrized Constructor that intializes members for setting the values of data fields
    * @param[in,out] data: for storing the alphabet char data type in the node of binary tree
	* @pre	Precondition: Constructor should be called with atleast one parameter of char type
	* @post	Postcondition: Sets the inital values of code, the data stored in node, left subtree & right subtree
	* Method Output: 
	* Sets the node ready in the tree. The name of the node is set to the alphabet i.e data
	* It's a new node so it's left subtree & right subtree is set to null
    * @bug		No known bugs
*****************************************************************************************************************************/
	Node(char data)
	{
		///assigning the letter of the node to the data part of the node
		this->data = data;

		///initializing the code as "" so it does not display any other garbage data
		code = "";

		///initially storing the left subtree to Null, since we have not inserted anything yet
		leftSubTree = NULL;

		///initially storing the right subtree to Null, since we have not inserted anything yet
		rightSubTree = NULL;
	}

	/// Destructor for destructing the member variables, else they will hold memory
	~Node(){};

	/*****************************************************************************************************************************
	* @brief	Module Name is Create Tree Function
    * @author	Faiza Fatma Siddiqui
    * @date	25-11-2021 (Created & Modified)
    * @details Purpose is to read text file and create a Binary Tree with letters and codes. This function takes 2 parameters: 
    * Description: The input file is read line by line, every alphabet is stored in a node of the tree. First, root node is filled, 
	* 	then the left and right subtrees are filled depending on the morse code found in the input file for a-z alphabets
    * @param[in,out] Node* rootPtr - takes the pointer of root node to create node of the tree
	* @param[in] ifstream& fileName - address of filename that stores the nodes of the tree i.e. alphabets
    * @return	null
	* @pre	Precondition: The file in the main function should be opened successfully otherwise this function will not work
	* @post	Postcondition: A binary tree is created in preorder traversal
	* Method Output: For every alphabet stored in the file, if the code after the alphabet starts with _, then node is inserted to the right subtree
		and if the morse code starts with a . then node is inserted to the left sub tree. 
	*	A binary search tree for all alphabets a-z is created.
	* @bug	No known bugs
*****************************************************************************************************************************/
	void createTree(Node *rootPtr, ifstream &myInputFile)
	{
		///to store the alphabet that is to be entered as data in the node
		char alphabet;

		///to store the first character of every line in the file
		string start;

		///to set the branch position as Null
		Node *branchPosition = NULL;

		/// loop until end of file is reached
		while (!myInputFile.eof())
		{
			///from input file read first character,which is the alphabet to be inserted, then the next character which is it's morse code
			myInputFile >> alphabet >> start;

			///@if the morse code starts with a . insert to the left sub tree
			if (start.at(0) == '.')
			{
				///@if left subtree is null then a new node should be created
				if (rootPtr->leftSubTree == NULL)
				{
					///creating new node for empty left subtree
					rootPtr->leftSubTree = new Node;
				}
				///@endif
				///now the root node is found and branch position is pointing to the left sub tree
				branchPosition = rootPtr->leftSubTree;
			}
			///@ifnot does the morse code starts with a _ insert to the right sub tree
			else if (start.at(0) == '_')
			{
				///@if right subtree is null then a new node should be created
				if (rootPtr->rightSubTree == NULL)
				{
					///creating new node for empty right subtree
					rootPtr->rightSubTree = new Node;
				}
				///@endif
				///now the root ptr is found and branch position is pointing to the right subtree
				branchPosition = rootPtr->rightSubTree;
			}
			///@endif
			/// After the root node is found, follow the rest of the path & keep inserting the alphabets in the tree
			for (unsigned int i = 1; i < start.size(); i++)
			{
				///@if the morse code starts with a ., then insert to the left sub tree
				if (start.at(i) == '.')
				{
					///@if left subtree is null then a new node should be created
					if (branchPosition->leftSubTree == NULL)
					{
						///creating new node on left
						branchPosition->leftSubTree = new Node;
					}
					///@endif
					///now the current position is on the left of the tree
					branchPosition = branchPosition->leftSubTree;
				}
				///@ifnot does the morse code starts with a _, then insert to the right sub tree
				else if (start.at(i) == '_')
				{
					///@if right subtree is null then a new node should be created
					if (branchPosition->rightSubTree == NULL)
					{
						///creating new node on right
						branchPosition->rightSubTree = new Node;
					}
					///@endif
					///now the current position is on the right of the tree
					branchPosition = branchPosition->rightSubTree;
				}
				///@endif
			}
			/// Fill the current position with the data that is the alphabet to be inserted in the tree
			branchPosition->data = alphabet;

			/// Attach the code of the alphabet along with the current node
			branchPosition->code = start;

			///empty the current branch position to store other values in the loop
			branchPosition = NULL;
		}
	}

	/*****************************************************************************************************************************
	* @brief	Module Name is Find Letter Function
    * @author	Faiza Fatma Siddiqui
    * @date	25-11-2021 (Created & Modified)
    * @details Purpose is to find the morse code from given a letter & from a given root. 
    * Description: The alphabet can be a root node, or can be in the left subtree or right subtree
	* A recursive call is made to the function to find the code
    * @param[in,out] Node* rootPtr - pointer to root node to traverse & find the letter from the tree
	* @param[in] char lettertoFind - the alphabet to find so that it can be encoded
    * @return	bool found
	* @pre	Precondition: alphabet to find should be from a-z only as these are the only nodes in the tree
	* @post	Postcondition: returns true if letter is found, else returns false
	* Method Output: Finds the position of a given letter, returns true if found, false if not found
	* @bug	No known bugs
*****************************************************************************************************************************/
	bool findLetter(Node *rootPtr, char lettertoFind)
	{
		///the current position is set to null
		Node *branchPosition = NULL;

		///a flag to find the letter
		bool found = false;

		/// @if letter is found at the root, print and return true
		if (rootPtr->data == lettertoFind)
		{
			///if the letter is at the root, print it
			cout << rootPtr->code << " ";

			///store the data of root node if found there, as the morse code encoded in a string
			morse_encoded = morse_encoded + rootPtr->code + " ";

			///return true since letter is found
			return true;
		}
		///@ifnot letter is not find on the root node, then check left & right sub tree
		else if (rootPtr->data != lettertoFind)
		{
			///@if left sub tree is empty, then root will point to left subtree
			if (rootPtr->leftSubTree != NULL)
			{
				///set the current branch position to the left sub tree
				branchPosition = rootPtr->leftSubTree;

				///recursive call to the left subtree until the letter is found
				found = findLetter(branchPosition, lettertoFind);
			}
			///@endif
			///@if right sub tree is empty, then root will point to right subtree
			if (rootPtr->rightSubTree != NULL && found != true)
			{
				///set the current branch position to the right sub tree
				branchPosition = rootPtr->rightSubTree;

				///recursive call to the right subtree until the letter is found
				found = findLetter(branchPosition, lettertoFind);
			}
			///@endif
		}
		///@endif
		/// return boolean value true or false if letter is found
		return found;
	}

	/*****************************************************************************************************************************
	* @brief	Module Name is Find Code Function
    * @author	Faiza Fatma Siddiqui
    * @date	25-11-2021 (Created & Modified)
    * @details Purpose is to find the aplhabet from given a morse code & from a given root. 
    * Description: The morsecode can be found from the alphabet that is at root node, or can be in the left subtree or right subtree
	* A recursive call is made to the function to find the code
    * @param[in,out] Node* rootPtr - pointer to root node to traverse & find the letter from binary tree
	* @param[in] char code - the morse code to find it's letter from the tree, so that it can be decoded
    * @return	bool found, true if found, else false
	* @pre	Precondition: Code to find should be a proper morsecode as mentioned in the input file
	* @post	Postcondition: returns true if letter is found, else returns false
	* Method Output: Finds the position of a given code, returns true if found, false if not found
	* @bug	No known bugs
*****************************************************************************************************************************/
	bool findCode(Node *rootPtr, string code)
	{
		///the current position is set to null
		Node *branchPosition = NULL;

		///a flag to find the code
		bool found = false;

		///@if code is found, print and return true
		if (rootPtr->code == code)
		{
			///store the data of root node if found there, as the morse code decoded in a string
			morse_decoded = morse_decoded + rootPtr->data + " ";

			///return true since code is found
			return true;
		}
		///@ifnot found on the root node, then check left & right sub tree
		else if (rootPtr->code != code)
		{
			///@if left sub tree is empty, then root will point to left subtree
			if (rootPtr->leftSubTree != NULL)
			{
				///set the current branch position to the left sub tree
				branchPosition = rootPtr->leftSubTree;

				///recursive call to the left subtree until the code is found
				found = findCode(branchPosition, code);
			}
			///@endif
			///@if left sub tree is empty, then root will point to left subtree
			if (rootPtr->rightSubTree != NULL && found != true)
			{
				///set the current branch position to the right sub tree
				branchPosition = rootPtr->rightSubTree;

				///recursive call to the right subtree until the code is found
				found = findCode(branchPosition, code);
			}
			///@endif
		}
		///@endif
		/// return boolean value true or false if code is found
		return found;
	}

	/*****************************************************************************************************************************
	* @brief	Module Name is Encode Function
    * @author	Faiza Fatma Siddiqui
    * @date	25-11-2021 (Created & Modified)
    * @details Purpose is to encode a message entered by the user
    * Description: The delimeter between words is replaced with spaces then for every alphabet in the message, 
	* the node of the tree is traversed to find it's morse code & encode it.
    * @param[in,out] Node* rootPtr - pointer to root node: To find the morse code of every alphabet from the tree 
	* @param[in, out] string message - the message entered by the user that is to be encoded in morse code
    * @return	null
	* @pre	Precondition: The message should not contain any symbols or numbers
	* @post	Postcondition: The message is encoded
	* Method Output: A message entered by the user is encoded using a binary tree
	* @bug	No known bugs
*****************************************************************************************************************************/
	void encode(Node *rootPtr, string message)
	{
		///stores each letter from the message that is to be searched for encoding
		char lettertoFind;

		///replace the / delimeter with spaces, reversing that we did initially before calling the function
		std::replace(message.begin(), message.end(), '/', ' ');

		///to print the message entered by the user, for a well formatted output
		cout << " in Morse Code: ";

		///loop to traverse through every letter of the message entered
		for (unsigned int i = 0; i < message.size(); i++)
		{
			///loop to traverse through every letter of the message entered
			lettertoFind = message.at(i);

			///pass every letter of the message to the find Letter in the tree to encode it
			findLetter(rootPtr, lettertoFind);
		}
		cout << endl
			 << endl;
	}

	/*****************************************************************************************************************************
	* @brief	Module Name is Decode Function
    * @author	Faiza Fatma Siddiqui
    * @date	25-11-2021 (Created & Modified)
    * @details Purpose is to decode the morsecode of the message entered by the user to the original message
    * Description: The delimeter between words is replaced with spaces then for every morsecode, 
	* the node of the tree is traversed to find it's letter in the node to decode it.
    * @param[in,out] Node* rootPtr - pointer to root node: To find the alphabet of every morsecode from the binary tree 
	* @param[in, out] string morsecodeEncoded - the morsecode of the message entered by the user to decode it
    * @return	null
	* @pre	Precondition: The morsecode should be from the input file itself. The encoding should be done properly for this function to work
	* @post	Postcondition: The morsecode is decoded to the original message
	* Method Output: The morsecode of the message entered by the user is decoded using the binary tree
		The decoded message is then printed
	* @bug	No known bugs
*****************************************************************************************************************************/
	void decode(Node *rootPtr, string morsecodeEncoded)
	{
		///a string to save morse code portion to be encoded
		string morsecode;

		///replace the morse code with the delimeter as mentioned
		std::replace(morsecodeEncoded.begin(), morsecodeEncoded.end(), '/', ' ');

		///for all the elements of encoded message, search for the code
		for (unsigned int i = 0; i < morsecodeEncoded.size(); i++)
		{
			///@if space is encountered that means one morse code is received
			if (morsecodeEncoded.at(i) == ' ')
			{
				/// search for the morse code received
				findCode(rootPtr, morsecode);
			}
			///@else take one morse code at a time from morsecodeEncoded & go to the next morsecode
			else
			{
				morsecode += morsecodeEncoded.at(i);
			}
			///@endif
		}
		/// search for the morse code received from the binary tree to decode
		findCode(rootPtr, morsecode);

		///prints the decoded message
		cout << "Decoded Message: " << morsecodeEncoded << endl;
	}
};
#endif