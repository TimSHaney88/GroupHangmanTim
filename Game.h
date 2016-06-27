//This is the Game class for hangman

//Game.h header file for Game class

#include "Player.h"
#include "Dictionary.h"
using namespace std;


#ifndef _GAME_H_
#define _GAME_H_

class Game
{
private:
	//total number of wrong guesses a player can have before losing
	int wrongGuessesBeforeLoss;
	//how many letters are in the word chosen
	int wordLength;
	//holds the word chosen
	string word;

public :
	//initializes the game
	Game(Player player, Dictionary dictionary); //constructor 
	//reads the file from dictionary and chooses a word
	void getWordFromDictionary(Dictionary dictionary);
	//keeps the game playing
	void play(Player player, Dictionary dictionary);
	//checks if the player loses or wins 
	void winOrLoss(Player player);
	//gets characters already guessed
	//void getDisplayGuessedLetter(Player player);
	//resets the game
	void resetGame(Player player, Dictionary dictionary);
};
#endif