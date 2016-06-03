//This is the "Game" part for hangman

//Game.h header file for Game class

#include "Player.h"
#include "Dictionary.h"
using namespace std;


#ifndef _GAME_H_
#define _GAME_H_

class Game
{
private:
	int wrongGuessesBeforeLoss;
	int wordLength;
	string word;

public :
	Game(Player player, Dictionary dictionary); //constructor 
	void getWordFromDictionary(Dictionary dictionary);
	void play(Player player, Dictionary dictionary);
	void winOrLoss(Player player);
	void resetGame(Player player, Dictionary dictionary);
};
#endif