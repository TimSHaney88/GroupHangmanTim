#ifndef DICTIONARY_H
#define DICTIONARY_H

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
	string wordArray[100];

public:
	//word chosen for the game
	string selectWord;
	//default constructor
	Dictionary();
	//read the file with the given name
	void ReadFromFile(string fileName);
	//randomly selects a word
	void ChooseAWord();
	//call the function to get the selected word
	//string ReturnWord();


};


#endif

