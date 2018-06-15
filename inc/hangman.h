
#pragma once // include guard

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <sstream>

using namespace std;

const int MAXLENGTH = 80;
const int MAX_TRIES = 12;

int letterFill( char, char[], char[] );
void initializeUnknownWordWithStars( char[], char[] );
void startHangmanGame();
int getRandomNumber();
void welcomeTheUser( std::string playername );
char getGuessedLetterFromUser( char unknown_word [] );
bool checkIfAlreadyGuessedLetter( char guessed_letter, std::string already_guessed_letters );
bool isAlphabeticalLetter( char guessed_letter );
void displayNumberOfTriesLeft( int number_of_tries );
void displayAlreadyGuessedLetters( std::string already_guessed_letters );
void incrementNumberOfTriesAndAlreadyGuesssedLetters( char guessed_letter, std::string already_guessed_letters, int number_of_tries );

