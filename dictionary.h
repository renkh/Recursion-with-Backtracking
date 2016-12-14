/******************************************************************************
  Title          : dictionary.h
  Author         : Renat Khalikov
  Created on     : October  27, 2016
  Description    : Provided abstract Dictionary class, DictionaryData is the
  					concrete class, holds the dictionary contents provided
  					by the dictionary input file
  Purpose        : Provided abstract Dictionary class, write concrete class
  					and implement it's functions
  Usage          : 
  Build with     : 
*/
#ifndef __DICTIONARY_H__ 
#define __DICTIONARY_H__

#include <string> 
#include <vector> 
#include <fstream>
using namespace std ;

class Dictionary {
public:
	/* Dictionary () 
	 * 	Constructor fills dictionary object with words from the given 
	 *	input file stream. 
	 * 	@pre 	file must be opened for reading && must have one word stream 
	 *			per line and be in sorted order.
	 *	@post 	dictionary object is filled with words from file in sorted 
	 *			order.
	 *	@param 	ifstream & file [inout] stream to read
	 */
	Dictionary( ifstream & file );

	/** search ()
	 *	@pre 	keyword != NULL and prefix_length >= 0 
	 *	@param 	string keyword [in] key to search for in dictionary
	 *	@param	size_t prefix_length [in] number of initial chars to match
	 *	@return int
	 *			If prefix_length > 0, then if there is a word W in the
	 *			dictionary such that: W[0.. prefix_length −1] is identical to 
	 *			keyword [0.. prefix_length −1] then it returns its index in 
	 *			the dictionary, else −1.
	 *			If prefix_length == 0, this returns an index if and only if the
	 *			keyword matches a word in the list exactly, and −1 otherwise.
	 */
	int search ( string keyword , 
				size_t prefix_length);

	/** fillDictionaryVector ()
	 *	@pre 	dictionaryWord is filled with a word from input file
	 *	@param 	string dictionaryWord [in] word to be put into dictionary
	 *			vector 
	 *	@return none, dictionary vector is filled
	 */
	void fillDictionaryVector(string dictionaryWord);

	/** getDictionaryWord ()
	 *	@pre 	int wordPosition [in] contains position of the word that is
	 *			in a vector
	 *	@param 	string & word [in] word to be filled by the word in 
	 *			the dictionary
	 *	@param	int wordPosition [in] position in the vector that contains 
	 *			the dictionary word
	 *	@return specified word that is in the dictionary vector
	 */
	string getDictionaryWord(string word, int wordPosition);

	/** getDictionarySize ()
	 *	@pre 	none
	 *	@param 	int size [out] size of the vector to be passed out
	 *	@return size of the vector
	 */
	int getDictionarySize(int size);

private:
	// vector that stores the dictionary file contents
	vector<string> dictionaryVector;
};

#endif /* __DICTIONARY_H__ */

