#include "Player.h"

Player::Player() {
  num_trials = 0;
  num_wrong_guesses = 0;
  total_num_guesses = 0;  
}

void Player::SetNumOfTrials(int num_trials) {
  this->num_trials = num_trials;
}

void Player::AddNewGuess(char letter, bool isGuessCorrect) {
  if (!isGuessCorrect) {
    ++num_wrong_guesses;
  }
  ++total_num_guesses;
  list_char_guessed.push_back(letter);
}

bool Player::IsValid(char letter) {
  if ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z')) {
    return true;
  }
  return false;
}

int Player::GetNumOfWrongGuesses() {
  return num_wrong_guesses;
}

vector<char> Player::GetListOfCharGuessed() {
  return list_char_guessed;
}

int Player::GetTotalNumOfGuesses() {
  return total_num_guesses;
}

void Player::Reset() {
  num_trials = 0;
  num_wrong_guesses = 0;
  total_num_guesses = 0;
  list_char_guessed.clear();
}