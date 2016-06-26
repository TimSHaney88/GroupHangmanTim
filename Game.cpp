#include "Game.h"
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

Game::Game(Player player, Dictionary dictionary)
{
	//welcomes the player
	cout << "Welcome to haaangmaaan! The goal of this game is to guess a word by suggesting\n";
	cout << "different letters. You have 8 chances to win!\n";
	//initializes the variable
	wrongGuessesBeforeLoss = 8;
	//calls the function to get the word from the dictionary
	getWordFromDictionary(dictionary);
	//welcoming continues
	cout << "Just so you know, your word has " << wordLength << " letters. GOOD LUCK!\n\n";
	//calls the function to play the game
	play(player, dictionary);
}

//funtion to get the word from the dictionary
void Game::getWordFromDictionary(Dictionary dictionary)
{
	//name of file
	string fileName = "Dictionary.txt";
	//calls the ReadFromFile funtion from dictionary in order to read the file
	dictionary.readFromFile(fileName);
	//calls the ChooseAWord function from dictionary in order to choose a word for the game
	dictionary.chooseAWord();

	//sets the string word equal to the word choosen by dictionary
	word = dictionary.returnWord();
	//displays the word choosen in order to check if the game works
	//cout << word << "\n";
	//sets the int wordLenght variable equal to the number of letters in the word chosen
	wordLength = word.size();
}

//This is function plays the game
void Game::play(Player player, Dictionary dictionary)
{

	//holds a letter
	char letter;
	//holds the number of correct guesses tha player has
	int correctLetters = 0;
	//checks if each guess is correct or false
	bool isGuessCorrect = false;
	
	//new char array equal to the length of the word chosen 
	char *guessedletters = new char[wordLength];
	
	//loop to set each char in the guessedletters array equals to an underscore 
	for (int i = 0; i < wordLength; i++)
	{
		guessedletters[i] = '_';
		//cout << guessedletters[i] << " ";
	}

	//loop to play the game
	while ((player.getNumOfWrongGuesses() < wrongGuessesBeforeLoss) && (correctLetters != wordLength))
	{
		//prompts the user to guess a letter 
		cout << "Guess a letter: ";
		cin >> letter;

		//checks if the input from the user is a valid letter
		if (player.isValid(letter) == true)
		{
			//loop to check if the letter is in the word
			for (int i = 0; i < wordLength; i++)
			{
				//checks if the letter guessed is equal to every letter in the word 
				if (letter == word[i])
				{
					//changes the char underscore for the letter guesses
					guessedletters[i] = letter;
					//increments the variable correctLetters by one
					correctLetters++;
					//sets the isGuessCorrect variable equals to true
					isGuessCorrect = true;
				}
			}
			//checks if the isGuessCorrect varible is equal to false
			if (isGuessCorrect == false)
			{
				//lets the player know that the letter is not in the word
				cout << "That letter is not in the word, try again!\n\n";
				//calls the AddNewGuess function from player to increment the number of wrong guesses and total guesses by one
				player.addNewGuess(letter, isGuessCorrect);
			}
			else
			{
				//lets the player know that the letter is in the word
				cout << "You guessed a letter!\n";
				//calls the AddNewGuess function from player to increment the number of total guesses by one
				player.addNewGuess(letter, isGuessCorrect);
			}
			
			//loop to display the guessedletters array so the player knows the letters guessed and get an idea of the word 
			for (int i = 0; i < wordLength; i++)
			{
				cout << guessedletters[i] << " ";
			}

			//sets the isGuessCorrect to false again 
			isGuessCorrect = false;
						
		}

		
		cout << "\n\nLetters guessed: ";
		//calls the GetListOfCharGuessed funtion from player to display the list of all the letters guessed
		player.getListOfCharGuessed();
		cout << "\n";
		//calls the GetNumOfWrongGuesses from player to display the number of wrong guesses
		cout << "How many wrong guesses?: " << player.getNumOfWrongGuesses() << "\n\n";
	}
	
	//calls the function to check if the player loses or wins 
	winOrLoss(player);
	//hold the answer yes or no
	string answer;
	//prompts the player to play again
	cout << "Would you like to play again? YES or NO ";
	cin >> answer;
	//if the answer is yes the game resets and the game continues
	if (answer == "YES" || answer == "yes" || answer == "y" || answer == "Y")
		resetGame(player, dictionary);
}

//This function checks if the player wins or loses
void Game::winOrLoss(Player player)
{
	//checks if the number of wrong guesses is equal to the total number of wrong guesses allowed by the game
	if (player.getNumOfWrongGuesses() == wrongGuessesBeforeLoss)
	{
		//lets the player know that he or she lost
		cout << "I'm sorry, but YOU LOST :(\n" << "The word is " << word << "\n\n";
	}
	else
	{
		//lets the player know that he or she won
		cout << "CONGRATS, YOU WON!\n"<< "The word is " << word << "\n\n";
	}

}

//this function resets the game
void Game::resetGame(Player player, Dictionary dictionary)
{
	//calls the Reset function from player to reinitiate the variable from the player class
	player.reset();
	//calls the function in order to choose a new word for the game
	getWordFromDictionary(dictionary);
	//calls the function to play the game again
	play(player, dictionary);
}