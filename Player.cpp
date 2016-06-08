#include "Player.h"

Player::Player() {
  num_wrong_guesses = 0;
  total_num_guesses = 0;  
}

void Player::addNewGuess(char letter, bool isGuessCorrect) {
  if (!isGuessCorrect) {
    ++num_wrong_guesses;
  }
  ++total_num_guesses;
  list_char_guessed.push_back(letter);
}

bool Player::isValid(char letter) {
  if ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z')) {
    return true;
  }
  return false;
}

int Player::getNumOfWrongGuesses() {
  return num_wrong_guesses;
}

vector<char> Player::getListOfCharGuessed() {
  return list_char_guessed;
}

int Player::getTotalNumOfGuesses() {
  return total_num_guesses;
}

void Player::reset() {
  num_wrong_guesses = 0;
  total_num_guesses = 0;
  list_char_guessed.clear();
}