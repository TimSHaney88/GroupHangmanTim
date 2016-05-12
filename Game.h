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
	int totalWrongGuesses;
	Player player();
	Dictionary dictionary();
	char *word;

public :
	Game(int totalWrongGuesses); //constructor 
	void Play(Player player, Dictionary dictionary, int totalWrongGuesses, char *word);
	void winOrLoss(Player player, int totalWrongGuesses, char *word, Dictionary dictionary);
	void resetGame(char *word);
};
#endif