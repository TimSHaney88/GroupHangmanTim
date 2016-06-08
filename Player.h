#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>
#include "iostream"
using namespace std;

class Player {
public:
  // Constructor initialises all the variables to zero.
  Player();

  // Sets number of trials allowed for the player.
  //void GetNumOfTrials(int num_trials);

  // Records the new letter guessed by the player.
  void addNewGuess(char letter, bool isGuessCorrect);
  // Verifies if the input letter is an alphabet or not.
  bool isValid(char letter);

  // Returns number of wrong guesses.
  int getNumOfWrongGuesses();
  // Returns total number of guesses (wrong+right).
  int getTotalNumOfGuesses();
  // Returns the list of the characters guessed by the player.
  vector<char> getListOfCharGuessed();
  void displayGuessedLetter();

  // Sets all the variables to zero and clears the guessed list.
  void reset();
  
private:
  // Stores number of wrong guesses.
  int num_wrong_guesses;
  // Stores total number of guesses. 
  int total_num_guesses;
  // Stores list of characters guessed by the player.
  vector<char> list_char_guessed;
};
#endif
