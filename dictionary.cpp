/******************************************************************************
  Title          : dictionary.cpp
  Author         : Renat Khalikov
  Created on     : October  27, 2016
  Description    : Dictionary class implementation
  Purpose        : Provided abstract Dictionary class, write concrete class
  					and implement it's functions
  Usage          : 
  Build with     : g++ -c -Wall dictionary.cpp
*/
#include "dictionary.h"
#include <string>
#include <iostream>
using namespace std;

// Constructor fills dictionary object with words from the given input 
// file stream.
Dictionary::Dictionary(ifstream & file)
{
	string word;
	while(file >> word)
	{
		fillDictionaryVector(word);
	}
}

// search function that returns the index if the keyword is in the dictionary
// vector
int Dictionary::search(string keyword, size_t prefix_length)
{
	string dictionaryWord = " ";
	int dictionarySize = 0;
	dictionarySize = getDictionarySize(dictionarySize);
	// If prefix_length > 0, then if there is a word W in the dictionary 
	// such that: W[0.. prefix_length −1] is identical to 
	// keyword [0.. prefix_length −1] then it returns its index in 
	// the dictionary, else −1.
	if (prefix_length > 0)
	{
		for (int i = 0; i < dictionarySize; ++i)
		{
			dictionaryWord = getDictionaryWord(dictionaryWord, i);
			size_t found = dictionaryWord.find(keyword);
			if (0 != found)
			{
				return i;
			}
		}
		return -1;
	}

	// If prefix_length == 0, this returns an index if and only if the
	// keyword matches a word in the list exactly, and −1 otherwise.
	else
	{
		for (int i = 0; i < dictionarySize; ++i)
		{
			dictionaryWord = getDictionaryWord(dictionaryWord, i);
			if (keyword == dictionaryWord)
			{
				return i;
			}
		}
		return -1;
	}
}

// function that adds a word from Dictionary file to a vector
void Dictionary::fillDictionaryVector(string dictionaryWord)
{
	dictionaryVector.push_back(dictionaryWord);
}

// returns the word that is specified by it's index position
string Dictionary::getDictionaryWord(string word, int wordPosition)
{
	return word = dictionaryVector[wordPosition];
}

// returns the dictionary vector size
int Dictionary::getDictionarySize(int size)
{
	return dictionaryVector.size();
}
