#include "Game.h"
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

Game::Game(Player player, Dictionary dictionary)
{
	cout << "Welcome to haaangmaaan! The goal of this game is to guess a word by suggesting\n";
	cout << "different letters. You have 3 chances to win!\n";
	wrongGuessesBeforeLoss = 3;
	getWordFromDictionary(dictionary);
	cout << "Just so you know, your word has " << wordLength << " letters. GOOD LUCK!\n\n";
	play(player, dictionary);
}


void Game::getWordFromDictionary(Dictionary dictionary)
{
	string fileName = "Dictionary.txt";
	dictionary.ReadFromFile(fileName);
	dictionary.ChooseAWord();

	
	word = dictionary.ReturnWord();
	//cout << word << "\n";
	wordLength = word.size();
}

void Game::play(Player player, Dictionary dictionary)
{

	char letter;
	int correctLetters = 0;
	bool isGuessCorrect = false;
	
	char const *wordToChar = word.c_str();
	char *guessedletters = new char[wordLength];
	
	for (int i = 0; i < wordLength; i++)
	{
		guessedletters[i] = '_';
		//cout << guessedletters[i] << " ";
	}

	/*for (int i = 0; i <wordLength; i++)
		cout << word[i];*/


	while ((player.GetNumOfWrongGuesses() < wrongGuessesBeforeLoss) && (correctLetters != wordLength))
	{
		cout << "Guess a letter: ";
		cin >> letter;


		if (player.IsValid(letter) == true)
		{
			for (int i = 0; i < wordLength; i++)
			{
				if (letter == word[i])
				{
					guessedletters[i] = letter;
					correctLetters++;
					isGuessCorrect = true;
				}
			}
			
			if (isGuessCorrect == false)
			{
				cout << "That letter is not in the word, try again!\n\n";
				player.AddNewGuess(letter, isGuessCorrect);
			}
			else
			{
				cout << "You guessed a letter!\n";
				player.AddNewGuess(letter, isGuessCorrect);
			}
			
			for (int i = 0; i < wordLength; i++)
			{
				cout << guessedletters[i] << " ";
			}

			isGuessCorrect = false;
						
		}

		cout << "\n\nLetters guessed: ";
		player.GetListOfCharGuessed();
		cout << "\n";
		cout << "How many wrong guesses?: " << player.GetNumOfWrongGuesses() << "\n\n";
	}
	
	winOrLoss(player);
	string answer;
	cout << "Would you like to play again? YES or NO ";
	cin >> answer;
	if (answer == "YES" || answer == "yes")
		resetGame(player, dictionary);
}

void Game::winOrLoss(Player player)
{
	if (player.GetNumOfWrongGuesses() == wrongGuessesBeforeLoss)
	{
		cout << "I'm sorry, but YOU LOST :(\n" << "The word is " << word << "\n\n";
	}

	else
	{
		cout << "CONGRATS, YOU WON!\n"<< "The word is " << word << "\n\n";
	}

}

void Game::resetGame(Player player, Dictionary dictionary)
{
	player.Reset();
	getWordFromDictionary(dictionary);
	play(player, dictionary);
}