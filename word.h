/******************************************************************************
  Title          : word.h
  Author         : Renat Khalikov
  Created on     : October  27, 2016
  Description    : Word class that represents a single source word, used to
  					check validity of the word, convert the word to 
  					lowercase, and find all rearangements of the
  					word
  Purpose        : Provide functionality for the source word
  Usage          : 
  Build with     : 
*/
#ifndef __WORD_H__ 
#define __WORD_H__

#include <string> 
#include "dictionary.h"
#include <vector> 
#include <fstream>
using namespace std ;

class Word
{
public:
	Word();
	~Word();
	/** checkValidity ()
	 *	@pre 	none
	 *	@param 	string keyword [in] word to be checked for validity
	 *	@param	bool & result [in] true or false if the string is valid or not
	 *	@return true if the string is of length >= 2 and <= 32, otherwise false
	 */
	void checkValidity(string & sourceWord, bool &result);

	/** toLowerCase ()
	 *	@pre 	none
	 *	@param 	string str [in] string contains upper case letters
	 *	@return none, passed by reference, string is in lower case
	 */
	void toLowerCase(string &str);

	/** makeWords ()
	 *	@pre 	Dictionary object is initialized, keyword contains 
	 *			the sourceword to make permutations with
	 *	@param 	Dictionary dictObject [in] dictionary object passed
	 *			in in order to call it's functions
	 *	@param 	string keyword [in] is the source word that will
	 *			be used to make substrings or permutations of 
	 *			substrings
	 *	@return none, void function
	 */
	void makeWords(Dictionary dictObject, string keyword);

	/** backtrack ()
	 *	@pre 	string w and string z are initialized
	 *	@param	Dictionary dictObject [in] object of dictionary class
	 *	@param 	string w [in] string contains a word to be checked if 
	 *			it is in dictionary and if it is a prefix of a word in
	 *			dictionary
	 *	@param 	string z [in] string contains all other unused 
	 *			characters in w
	 *	@return none, void function
	 */
	void backtrack(Dictionary dictObject, string w, string z);

	/** prefixDictionary ()
	 *	@pre 	string w must have a word in it
	 *	@param 	string w [in] string contains a word to be checked if 
	 *			it is a prefix of a word in dictionary
	 *	@param 	Dictionary dictObject [in] object of dictionary class
	 *	@return none, void function
	 */
	bool prefixDictionary(string w, Dictionary dictObject);

	/** inDictionary ()
	 *	@pre 	string w must have a word in it
	 *	@param 	string w [in] string contains a word to be checked 
	 *			in dictionary
	 *	@param 	Dictionary dictObject [in] object of dictionary class
	 *	@return none, void function
	 */
	bool inDictionary(string w, Dictionary dictObject);

	/** inputSolution ()
	 *	@pre 	word is a valid solution, it exists in the dictionary
	 *	@param 	DictionaryData dictObject [in] dictionary class object used
	 *			to call the getDictionaryWord function
	 *	@param 	string word [in] word to insert into solution vector
	 *	@param 	int index [in] position of the word that is in the dictionary
	 *			vector
	 *	@return void no return
	 */
	void inputSolution(Dictionary dictObject, string word, int index);

	/** inputToVector ()
	 *	@pre 	word is a valid solution, it exists in the dictionary
	 *	@param 	string word [in] word to insert into solution vector
	 *	@return void no return
	 */
	void inputToVector(string word);

	/** getVectorSize ()
	 *	@pre 	size of the vector is defined
	 *	@param 	int size [out] returns the size of the vector
	 *	@return the vector size
	 */
	int getVectorSize(int size);

	/** getSolution ()
	 *	@pre 	solution vector contains words
	 *	@param 	string word [out] word to be passed out of the vector
	 *	@param 	int i [in] index that the word is in
	 *	@return the word stored in the vector
	 */
	string getSolution(string word, int i);

	/** printSolution ()
	 *	@pre 	solution vector contains words to be printed
	 *			to a screen
	 *	@param 	none
	 *	@return none
	 */
	void printSolution();

	/** printTestwords ()
	 *	@pre 	solution vector contains words to be passed into
	 *			an output file, output file is open
	 *	@param 	ofstream & file [in] file to be used to put 
	 *			words into
	 *	@param 	string word [in] word is the source word that
	 *			was used to make permutations with
	 *	@return the words are stored in the file
	 */
	void printTestwords(ofstream & file, string word);

	/** printTestwords ()
	 *	@pre 	file is opened for reading, outputfile is
	 *			open for writing
	 *	@param 	ifstream & file [in] file contains the source 
	 *			words
	 *	@param 	ofstream & outputfile [in] file used to write
	 *			all possible permutations with source words 
	 *			that are contained in file
	 *	@return none
	 */
	void readTestwords(ifstream & file, ofstream & outputFile, Dictionary dictObject);
private:
	// contains all possible substrings or permutations of substrings
	vector<string> solution;
};

#endif /* __WORD_H__ */

