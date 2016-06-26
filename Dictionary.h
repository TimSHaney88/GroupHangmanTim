#ifndef DICTIONARY_H
#define  DICTIONARY_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Dictionary
{
private:
	//number of words in the document
	int wordCount;
	//keep all of the words from the file into the array
	string wordArray[1000];
	string* ptr;
	//word chosen for the game
	string selectWord;

public:
	
	//default constructor
	Dictionary();
	//read the file with the given name
	void readFromFile(string fileName);
	//randomly selects a word
	void chooseAWord();
	//call the function to get the selected word
	 string returnWord();
	 string* pointer();
};


#endif