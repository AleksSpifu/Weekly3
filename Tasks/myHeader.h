#pragma once

int guessMin = 1;
int guessMax = 0;
int correctNumber = 5;
int guess;
bool wonTheGame = false;
int attempts = 0;
std::string username[11];
int highscore[11];
int activeUser = 0;
bool donePlaying = false;
int goAgainChoice;

void difficultySetting();
void changeDifficulty();
int goAgainMenu();
void guessingProcess();
void userSelection();
void getUserName();
void getNumberFromUser();
int getRandomNumber(int min, int max);
