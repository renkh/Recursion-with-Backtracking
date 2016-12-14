/******************************************************************************
  Title          : main.cpp
  Author         : Renat Khalikov
  Created on     : October  27, 2016
  Description    : Having been given a source word, find all words that are
  					rearrangements of one or more of the characters in the
  					source word, that are also in the dictionary.
  Purpose        : Write a backtracking program using recursion
  Usage          : 
  Build with     : g++ -o proj2 main.o dictionary.o word.o
*/
#include <iostream>
#include <fstream>
#include <cstdlib> // exit() call
#include <string>
#include "dictionary.h"
#include "word.h"
using namespace std;

int main(int argc, char const *argv[])
{
	// test commands are opened successfully
	if (argc < 2)
	{
		/* handle incorrect usage here */
		cerr << "usage: " << argv[0] << " dictionary filename\n";
		exit(1);
	}

	// open the dictionary file
	ifstream dictionary_file(argv[1]);
	if (dictionary_file.fail()){
		cerr << "Could not open " << argv[1] << endl;
		exit(1); // 1 indicates an error occurred
	}

	// open the testwords file
	ifstream testwordsFile(argv[2]);
	if (NULL!=argv[2])
	{
		if (testwordsFile.fail()){
			cerr << "Could not open " << argv[2] << endl;
			exit(1); // 1 indicates an error occurred
		}
	}

	// The program should store the dictionary in a suitable data structure 
	// in memory, calls default constructor
	Dictionary dictionaryObj(dictionary_file);

	// used for do while loop
	char ans = 'N';

	// do while loop, will repeatedly ask user to continue after the 
	// program has finished displaying the words
	do 
	{
		// created a Word class object
		Word wordObj;

		// if the user supplied just one argument
		if (NULL==argv[2])
		{
			// repeatedly prompt the user to enter a string of at least 2 
			// and at most 32 characters
			string sourceWord;
			cout << "Enter a word: " << endl;
			cin >> sourceWord;

			// check the validity of the word
			bool result = false;
			wordObj.checkValidity(sourceWord, result);

			// If the user enters any upper case letters, the program should 
			// convert them to lowercase before it tries to form words.
			wordObj.toLowerCase(sourceWord);

			// forms all words that are substrings or permutations of 
			// substrings of the user’s word that are also in the dictionary
			wordObj.makeWords(dictionaryObj, sourceWord);

			// output the solution to the screen
			wordObj.printSolution();

			// ask the user if she wants to continue
		    cout << "Do you want to continue (Y/N)?\n";
		    cin >> ans;
		}

		// If there is a second argument, program should not do anything
		// interactively
		else
		{
			// names the output file to user's supplied second argument file
			string outputFileName = argv[2];
			outputFileName = outputFileName.substr(0, outputFileName.length()-3);
			// appends the ".out" extension
			outputFileName.append("out");
			ofstream outputFile;
			outputFile.open(outputFileName.c_str());

			// forms all words that are substrings or permutations of 
			// substrings of testwords file that are also in the dictionary
			wordObj.readTestwords(testwordsFile, outputFile, dictionaryObj);
		}

  	} while ((ans == 'Y') || (ans == 'y'));
	return 0;
}

