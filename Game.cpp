#include "Game.h"
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

Game::Game(int totalWrongGuesses)
{
	cout << "Welcome to hangman!(write the instructions)";
	totalWrongGuesses = 3;
}

void Game::Play(Player player, Dictionary dictionary, int totalWrongGuesses, char *word)
{

	char letter;

	int correctLetters = 0;

	string temp = dictionary.ReturnWord();
	int wordLength = temp.size();

	word = new char[wordLength + 1];
	word[wordLength] = 0;
	memcpy(word, temp.c_str(), wordLength);

	while (player.GetNumOfWrongGuesses() < totalWrongGuesses && correctLetters != wordLength)
	{
		cout << "Guess a letter";
		cin >> letter;

		if (player.IsValid(letter) == true)
		{
			for (int i = 0; i < wordLength; i++)
			{
				if (letter == word[i])
				{
					cout << letter;
					correctLetters++;
				}

				else
					i++;
			}
		}
	}
}

void Game::winOrLoss(Player player, int totalWrongGuesses, char *word, Dictionary dictionary)
{
	if (player.GetNumOfWrongGuesses() == totalWrongGuesses)
	{
		cout << "YOU LOST\n" << "The word is " << dictionary.ReturnWord();
		player.Reset();
		resetGame(word);
	}

	else
	{
		cout << "YOU WIN\n"<< "The word is " << dictionary.ReturnWord();
		player.Reset();
		resetGame(word);
	}

}

void Game::resetGame(char *word)
{
	delete [] word;

}