/*****************************************************************************************************************************
	* @file		MorseCode.cpp
    * @brief	Module Name is Morse Code Encoder Decoder
    * @author	Faiza Fatma Siddiqui, StudentID: 200473896
    * @date		25-11-2021 (Created & Modified)
    * @details 	This program is user-friendly and it does the following:
	*	- Prompts the user to enter a message to encode
	*	- It then encodes that message using morse code and displays an encoded message in the form of dots and dashes
	*	- It creates a tree for storing all the alphabets, the tree has a depth of 4. 
	*	- It then decodes the morse code and returns the original message entered by the user.
    * Purpose:	CS 700 - Software Development Fundamentals - Assignment 5
	* Method Output: Enter a message, then it is encoded in morse code.
	* @pre		Use only alphabets to encode, not numbers or symbols
    * @bug		No known bugs.
	* @warning	Improper use can crash the program while taking input from the user
*****************************************************************************************************************************/

/// This header file includes all standard libraries 
#include <bits/stdc++.h>

///header file that contains function all string manipulation functions
#include <string.h>

#include<iostream>
#include<conio.h>
#include<cctype>
#include "Tree.h"
/// This file includes all standard libraries
using namespace std;


/*****************************************************************************************************************************
 	* @brief	Module Name is Main Function
    * @author	Faiza Fatma Siddiqui
    * @date	25-11-2021 (Created/Modified)
    * @details Purpose is to print message to user to call create tree, encode, decode or function
    * Description: This function reads the input file to create morse code tree, prompts the user to ente. 
	*	- It calls the function for Creating the tree
	*	- It calls the function for Encoding the message
	*	- It calls the function for Decoding the message
    * @param	None
    * @return	integer - 0 if program executed successfully, else nonzero will be returned
	* @pre	Precondition: User should input alphabets only, not numbers or symbols
	* @post	Postcondition: 
	* Method Output: 
	*
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

	// Close text file.
	inputFile.close();

	return 0;
}