/******************************************************************************
  Title          : word.cpp
  Author         : Renat Khalikov
  Created on     : October  27, 2016
  Description    : Word class implementation
  Purpose        : Provide functionality for the source word
  Usage          : 
  Build with     : g++ -c -Wall word.cpp
*/
#include "word.h"
#include "dictionary.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm> // used for sort
using namespace std;

// default constructor
Word::Word()
{

}

// default destructor
Word::~Word()
{
	
}

// checks if the user's input word is valid
void Word::checkValidity(string & sourceWord, bool & result)
{
	while(!result)
	{
		result = true;
		if(sourceWord.length() < 2 || sourceWord.length() > 32)
		{
			cout << "Please enter a word of at least 2 and at most 32 characters" << endl;
			cin >> sourceWord;
			result = false;
		}
		if (sourceWord.length() >= 2 && sourceWord.length() <= 32)
		{
			result = true;
		}
	}
}

// If the user enters any uppercase letters, the function will 
// convert them to lowercase
void Word::toLowerCase(string &str)
{
	const int length = str.length();
	for(int i=0; i < length; ++i)
	{
		str[i] = tolower(str[i]);
	}
}

// initializes w to an empty string and z to source word and 
// calls backtrack function to find its permutations
void Word::makeWords(Dictionary dictObject, string keyword)
{
	string w = "";
	string z = keyword;
	backtrack(dictObject, w, z);
}

// recursive function that finds all permutations of a word w
void Word::backtrack(Dictionary dictObject, string w, string z)
{
	for (unsigned i = 0; i < z.length(); ++i)
	{
		// ​check whether w is in the dictionary.
		if (inDictionary(w, dictObject))
		{
			// ​If it is, we add it to the list of solutions we have found
			int vectorIndex = dictObject.search(w, 0);
			inputSolution(dictObject, w, vectorIndex);
		}
		
		// ​We next check whether w is a preﬁx of a word in the dictionary.
		if (prefixDictionary(w, dictObject))
		{
			// If it is, then w is a partial solution to our problem and we 
			// want to extend it to a solution by picking each letter in z 
			// and appending it to w and checking whether this is either a 
			// solution or a partial solution.
			backtrack(dictObject, w + z[i], string(z).erase(i,1));
		}

		// if w is not a prefix of a word in the dictionary, return from
		// this call
		if (!prefixDictionary(w, dictObject))
		{
			return;
		}
	}
}

// checks whether w is in the dictionary vector
bool Word::inDictionary(string w, Dictionary dictObject)
{
	string dictionaryWord;
	int dictionarySize = 0;
	dictionarySize = dictObject.getDictionarySize(dictionarySize);
	// ​check whether w is in the dictionary.
	for (int i = 0; i < dictionarySize; ++i)
	{
		dictionaryWord = dictObject.getDictionaryWord(dictionaryWord, i);
		if (w == dictionaryWord)
		{
			return true;
		}
	}
	return false;
}

// checks whether w is a prefix of a word in the dictionary
bool Word::prefixDictionary(string w, Dictionary dictObject)
{
	// checks the length of string w
	unsigned wLength = w.length();
	string dictionaryWord;
	int dictionarySize = 0;
	dictionarySize = dictObject.getDictionarySize(dictionarySize);
	for (int i = 0; i < dictionarySize; ++i)
	{
		dictionaryWord = dictObject.getDictionaryWord(dictionaryWord, i);
		// appends the prefix of dictionary word to empty string
		string word;
		if (wLength < dictionaryWord.length())
		{
			word.append(dictionaryWord, 0, wLength);
			// if the prefix is equal to string w, return true
			if (w == word)
			{
				return true;
			}
		}
	}
	return false;
}

// will input word into a list of solutions provided that word
// is a valid word
void Word::inputSolution(Dictionary dictObject, string word, int index)
{
	string addWord = dictObject.getDictionaryWord(word, index);
	int vectorSize = 0;
	vectorSize = getVectorSize(vectorSize);
	for (int i = 0; i < vectorSize; ++i)
	{
		string vectorWord;
		vectorWord = getSolution(vectorWord, i);
		// checks to see if the word exists in the dictionary
		// if it does, no need to add again
		if (vectorWord == addWord)
		{
			return;
		}
	}
	inputToVector(addWord);
}

// inputs word to vector of solutions provided that word is
// a valid word to input, works in conjunction with
// inputSolution()
void Word::inputToVector(string word)
{
	solution.push_back(word);
}

// returns the solution vector size
// used for for loops
int Word::getVectorSize(int size)
{
	return solution.size();
}

// returns the word in solution vector.
// i is the index of the word to return
string Word::getSolution(string word, int i)
{
	// this will sort the vector in alphabetical 
	// order, used with #include <algorithm> 
	sort(solution.begin(), solution.end());
	word = solution[i];
	return word;
}

// will cout the contents of solution vector to the
// screen provided there are words in the vector
void Word::printSolution()
{
	int vectorSize = 0;
	vectorSize = getVectorSize(vectorSize);
	for (int i = 0; i < vectorSize; ++i)
	{
		string vectorWord;
		vectorWord = getSolution(vectorWord, i);
		cout << vectorWord << endl;
	}
}

// this will read the words from the second 
// file one at a time and compute the valid 
// substrings and permutations
void Word::readTestwords(ifstream & file, ofstream & outputFile, Dictionary dictObject)
{
	string word;
	while(file >> word)
	{
		// converts them to lower case
		toLowerCase(word);
		// finds all substrings and permutations
		makeWords(dictObject, word);
		// prints the words to outputfile
		printTestwords(outputFile, word);
	}
}

// will print the solution vector to an output file
// provided that the output file is open for reading
// and the vector has valid words to print
void Word::printTestwords(ofstream & file, string word)
{
	file << word << endl;
	int vectorSize = 0;
	vectorSize = getVectorSize(vectorSize);
	for (int i = 0; i < vectorSize; ++i)
	{
		string vectorWord;
		vectorWord = getSolution(vectorWord, i);
		file << vectorWord << endl;
	}
	file << endl;
}

