/****************************************************************************************************************************
	* @file main.cpp
   	* @brief	Module Name is Morse Code Encoder Decoder File
    * @author	Faiza Fatma Siddiqui
    * @date	25-11-2021 (Created/Modified)
    * @details Purpose is to call the main functions for creating tree, encoding in morse code and decoding
    * Description: This function opens the input text file that is morse.txt
	*	- It checks whether the file opened succeesfully or not, & gives an error if not found
	*	- It takes input from the user to encode a message in Morse Code
	*	- It calls the function for creating a binary tree
	*	- It calls the function for encoding the letters into morse code, then decoding the morse code to original message
    * Purpose:	CS 700 - Software Development Fundamentals - Assignment 5
	* Method Output: * Asks the user to input a message to encode
	* Encodes the message in Morse Code
	* Decodes and prints the original message from Morse Code 
    * @bug		No known bugs.
	* @warning	Improper use can crash the program while taking input from the user
*****************************************************************************************************************************/

/// This header file includes all standard libraries
#include <bits/stdc++.h>

///header file for creating tree, encoding & decoding from tree
#include "Tree.h"

/// tells the compiler to make all the names in the predefined standard library available to our program
using namespace std;

/*****************************************************************************************************************************
 	* @brief	Module Name is Main Function
    * @author	Faiza Fatma Siddiqui
    * @date	25-11-2021 (Created/Modified)
    * @details Purpose is to call the main functions for creating tree, encoding in morse code and decoding
    * Description: This function opens the input text file that is morse.txt
	*	- It checks whether the file opened succesfully or not & gives an error if not found
	*	- It takes input from the user to encode a message in Morse Code
	*	- It calls the function for creating a binary tree
	*	- It calls the function for encoding the letters into morse code, then decoding the morse code to original message
    * @param	None
    * @return	integer - 0 if program executed successfully, else nonzero will be returned
	* @pre	Precondition: Message entered by the user should not have numbers or symbols. Alphabets only
	* @post	Postcondition: Gives the encoded and decoded message
	* Method Output: 
	* Asks the user to input a message to encode
	* Encodes the message in Morse Code
	* Decodes and prints the original message from Morse Code 
*****************************************************************************************************************************/
int main()
{
	///object of class Node to hold the root
	Node root;

	///pointer to root node
	Node *rootPtr = &root;

	///stores the original message entered by the user
	string message;

	///input file that has morse code in preorder to build the tree
	ifstream inputFile;

	/// Open the input file
	inputFile.open("morse.txt");

	/// @if file did not open successfully
	if (inputFile.fail())
	{
		///if file not opened, give error and end the program
		cerr << "Error opening file." << endl;
		exit(1);
	}
	///@endif 

	/// take input from user
	cout << "Enter message to Encode: ";

	///store the message that is the whole line entered by the user in message string
	getline(std::cin, message);

	///to display the message entered by the user
	cout << endl << message;

	///to change all the capital letters to small letters because tree has only small letters
	transform(message.begin(), message.end(), message.begin(), ::tolower);

	///replace the spaces in the message with / a delimeter symbol as asked in the assignment to separate words with delimeter symbol
	std::replace(message.begin(), message.end(), ' ', '/');

	///calling the buildTree method with object of Node class
	root.createTree(rootPtr, inputFile);

	///calling the function for encoding the message with object of Node class
	root.encode(rootPtr, message);

	///Calling the function for decoding the encoded message with object of Node class
	root.decode(rootPtr, message);

	/// Close the input file
	inputFile.close();

	/// if program executed successfully because main function is of type integer
	return 0;
}