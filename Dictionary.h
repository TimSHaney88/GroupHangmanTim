#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Dictionary
{
private:
	int wordCount;
	string wordArray[1000];

public:
	string selectWord;
	Dictionary() {};
	void ReadFromFile(string) {};
	void ChooseAWord() {};
	string ReturnWord() {};




};


#endif

