//============================================================================
// Name        : Hangman_game.cpp
// Author      : Siri Persson
// Version     : 1
// Copyright   : Your copyright notice
// Description : Hangman game in C++
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <sstream>

using namespace std;

const int MAXLENGTH=80;
const int MAX_TRIES = 12;

int letterFill (char, char[], char[]);
void initializeUnknownWordWithStars (char[], char[]);

int main () {
	std::string playername;
	std::string already_guessed_letters;
	std::size_t found;
	int number_of_tries = 0;
	char guessed_letter;
	char unknown_word [MAXLENGTH];
	char word[MAXLENGTH];
	char allWords[][MAXLENGTH] ={
		"afghanistan",
		"bangladesh",
		"bahamas",
		"belgium",
		"botswana",
		"mexico",
		"bulgaria",
		"namibia",
		"mongolia",
		"singapore"
	};

	srand(time(NULL));
	int random_number = rand() % 10 +1;
	strcpy(word, allWords[random_number]);

	initializeUnknownWordWithStars(word, unknown_word);

	cout << "\nType your name: " << endl;
	cin >> playername;
	cout << "\nWelcome " << playername << " to this awesome Hangman game!" << endl;
	cout << "Guess a country name."<< endl;
	cout << "Each letter is represented by a star. You have to type only one letter in one try"<< endl;
	cout << "You have " << MAX_TRIES << " tries to try and guess the word"<< endl;

	while (number_of_tries < MAX_TRIES) {
		cout << unknown_word << endl;
		cout << "\nGuess a letter: " << endl;
		cin >> guessed_letter;
		guessed_letter = tolower(guessed_letter);

		std::string string_letter;
		stringstream ss;
		ss << guessed_letter;
		ss >> string_letter;
		found=already_guessed_letters.find(string_letter);

		if (found!=std::string::npos){
			cout << endl << "You have already guessed this letter. Try again!" << endl;
		}

		if( isalpha(guessed_letter) == 0 && found == std::string::npos){
			cout << endl << "You must enter an alphabetical letter. Try again!" << endl;
		} else if (found == std::string::npos){
			already_guessed_letters = already_guessed_letters + guessed_letter + " ";
			number_of_tries++;
		}

		if ( letterFill(guessed_letter, word, unknown_word)==0  && isalpha(guessed_letter) != 0 && found == std::string::npos ) {
			cout << endl << "Whoops! That letter isn't in there!" << endl;
			cout << "You have " << MAX_TRIES - number_of_tries << " guesses left." << endl;
			cout << "Already guessed letters: " << already_guessed_letters <<endl;
		}
		else if (isalpha(guessed_letter) != 0 && found == std::string::npos){
			cout << endl << "You found a letter! Isn't that exciting!" << endl;
			if (strcmp(word, unknown_word) == 0) {
				cout << word << endl;
				cout << "\nCongratulations " << playername <<", you won the game!" << endl;
				break;
			} else {
				cout << "You have " <<MAX_TRIES - number_of_tries << " guesses left." << endl;
				cout << "Already guessed letters: " << already_guessed_letters <<endl;
			}
		}
		if (number_of_tries == MAX_TRIES && isalpha(guessed_letter) != 0 && found == std::string::npos ) {
			cout << "\nSorry " << playername << ", you lose...you've been hanged." << endl;
			cout << "The word was : " << word << endl;
			break;
		}
	}
	getch(); // måste ha denna annars funkar inte inläggningen av gissningar
	return 0;
}


void initializeUnknownWordWithStars (char word[], char unknown_word[]) {
	int i;
	int wordlength = strlen(word);
	for (i = 0; i < wordlength; i++)
		unknown_word[i]='*';
	unknown_word[i]='\0';
}

int letterFill (char guess, char secretword[], char guessword[]) {
	int matches=0;
	for (int i = 0; secretword[i]!='\0'; i++) {
		if (guess == secretword[i]) {
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}
