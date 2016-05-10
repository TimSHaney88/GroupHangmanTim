#include "Dictionary.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

Dictionary::Dictionary()
{
	//initializing variables
	selectWord = "";
	wordCount = 0;
}
//function to read the file 
void Dictionary::ReadFromFile(string fileName)
{
	//temporary variable to hold input from file
	string temp;
	//read in file
	ifstream inFile(fileName);

	//read through file and stop at end
	while (!inFile.eof())
	{
		//read in each word
		getline(inFile, temp);

		//take temporary words from file and put into a word array
		wordArray[wordCount] = temp;
		//printing array of words from file to screen to check
		//cout << wordArray[wordCount] << endl;
		//increase index of array of words
		wordCount++;
	}
	//close file
	inFile.close();
}

//function to choose a random word from the array of words from the file
void Dictionary::ChooseAWord()
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
string Dictionary::ReturnWord()
{
	//returns randomly chosen word 
	return selectWord;
}
