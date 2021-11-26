There are 7 files:
1. Output Screenshots: VS Code and Command Prompt
2. Github repository & version history screenshots
3. The Source Code(MorseCode.cpp file)
4. The Header File(Tree.h)
5. Doxygen generated html file - check index.html in that folder
6. Input file - morse.txt that stores every alphabet and its morse code
7. A picture of binary Tree that was created

This program has been tested and can be run in Visual Studio Code & Command Prompt on Windows 10 with Mingw C++ Compiler

Github link for this program:
https://github.com/faizasiddiqui33/Assignment5.git

MorseCode.cpp is a C++ program that is a user-friendly and it does the following:
	- Prompts the user to enter a message to encode
	- It then encodes that message using morse code and displays an encoded message in the form of dots and dashes
	- It creates a tree for storing all the alphabets, the tree has a depth of 4. 
	- It then decodes the morse code and returns the original message entered by the user.
Morse code is a common code that is used to encode messages consisting of letters. 
Each letter consists of a series of dots and dashes.
Store each letter of the alphabet in a node of a binary tree of depth 4.
The root node is at depth 0 and stores no letter. The left node at depth 1 stores the letter e (code is •) 
and the right node stores the letter t (code is –). 
The four nodes at depth 2 store the letters with codes.
To build the tree read a file in which each line consists of a letter followed by its code.
The letters should be ordered by tree depth. To find the position for a letter in the tree, 
scan the code and branch left for a dot and branch right for a dash.
Encode a message by replacing each letter by its code symbol.
Make sure you use a delimiter symbol between coded letters.
Then decode the coded message using the Morse code tree.