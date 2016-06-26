#include "Dictionary.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

Dictionary::Dictionary()
{
	//initializing variables
	selectWord = "";
	wordCount = 0;
	//ptr = new string;
}
//function to read the file 
void Dictionary::readFromFile(string fileName)
{
	//temporary variable to hold input from file
	string temp;
	//read in file
	ifstream inFile(fileName);
	if (inFile.is_open())
	{
		//read through file and stop at end
		while (getline(inFile, temp))
		{

			//take temporary words from file and put into a word array
			wordArray[wordCount] = temp;
			//*ptr = temp;
			//printing array of words from file to screen to check
			//cout << wordArray[wordCount] << endl;
			//increase index of array of words
			ptr++;
			wordCount++;
		}
		//close file
		inFile.close();
	}
	else
	{
		cout << "File couldn't open"; 
	}
}

//function to choose a random word from the array of words from the file
void Dictionary::chooseAWord()
{
	//randomly generate a word from words from the word array with a seed value
	srand(time(NULL));
	int randomIndex = rand() % wordCount;
	//test to see index of random number
	//cout << randomIndex << endl;
	//take the random word chosen from the array of words and assign it to the select word variable

	selectWord = wordArray[randomIndex];

	
	//test print randomly generated word from word array 
	//cout << selectWord << endl;
}

//function to return randomly chosen word
string Dictionary::returnWord()
{
	//returns randomly chosen word 
	return selectWord;
	//return *ptr;
}
