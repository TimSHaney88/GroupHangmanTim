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
  void SetNumOfTrials(int num_trials);

  // Records the new letter guessed by the player.
  void AddNewGuess(char letter, bool isGuessCorrect);
  // Verifies if the input letter is an alphabet or not.
  bool IsValid(char letter);

  // Returns number of wrong guesses.
  int GetNumOfWrongGuesses();
  // Returns total number of guesses (wrong+right).
  int GetTotalNumOfGuesses();
  // Returns the list of the characters guessed by the player.
  vector<char> GetListOfCharGuessed();

  // Sets all the variables to zero and clears the guessed list.
  void Reset();
  
private:
  // Stores total number of trials.
  int num_trials;
  // Stores number of wrong guesses.
  int num_wrong_guesses;
  // Stores total number of guesses. 
  int total_num_guesses;
  // Stores list of characters guessed by the player.
  vector<char> list_char_guessed;
};
#endif
