//============================================================================
// Name        : Hangman_game.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hangman game in C++
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <typeinfo>

using namespace std;

const int MAXLENGTH=80;
const int MAXROW=7;
const int MAX_TRIES = 9;

int letterFill (char, char[], char[]);
void initUnknownWordWithStars (char[], char[]);

int main () {
	char unknown [MAXLENGTH];
	char letter;
	int number_of_tries = 0;
	char word[MAXLENGTH];
	char words[][MAXLENGTH] ={
		"afghanistan",
		"bangladesh",
		"bahamas",
		"belgium",
		"botswana",
		"mexico",
		"bulgaria",
		"namibia",
		"mongolia",
		"singapore",
		"indonesia"
	};

	//choose and copy a word from array of words randomly
	srand(time(NULL));
	int random_number = rand() % 10 +1;
	cout << "Random number: " << random_number << endl;
	strcpy(word, words[random_number]);

	initUnknownWordWithStars(word, unknown);

	cout << "Welcome to this awesome Hangman game!" << endl;
	cout << "Guess a country name."<< endl;
	cout << "Each letter is represented by a star. You have to type only one letter in one try"<< endl;
	cout << "You have " << MAX_TRIES << " tries to try and guess the word"<< endl;


	while (number_of_tries < MAX_TRIES) {
		cout << unknown << endl;
		cout << "\n\nGuess a letter: " << endl;
		cin >> letter;
		letter = tolower(letter); // To lowercase
		number_of_tries++;

		if (letterFill(letter, word, unknown)==0) {
			cout << endl << "\nWhoops! That letter isn't in there!" << endl;
			cout << "You have " << MAX_TRIES - number_of_tries << " guesses left." << endl;
		}
		else {
			cout << endl << "\nYou found a letter! Isn't that exciting!" << endl;
			cout << "You have " <<MAX_TRIES - number_of_tries << " guesses left." << endl;
			if (strcmp(word, unknown) == 0) {
				cout << word << endl;
				cout << "\nCongratulations, you won the game!" << endl;
				break;
			}
		}
		if (number_of_tries == MAX_TRIES) {
			cout << "\nSorry, you lose...you've been hanged." << endl;
			cout << "The word was : " << word << endl;
			break;
		}
	}
	getchar();
	return 0;
}

/* Take a one character guess and the secret word, and fill in the
 unfinished guessword. Returns number of characters matched.
 Also, returns zero if the character is already guessed. */

int letterFill (char guess, char secretword[], char guessword[]) {
	int i;
	int matches=0;
	for (i = 0; secretword[i]!='\0'; i++)
	{
		// Did we already match this letter in a previous guess?
		if (guess == guessword[i])
			return 0;
		// Is the guess in the secret word?
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}


void initUnknownWordWithStars (char word[], char unknown[]) {
	int i;
	int length = strlen(word);
	for (i = 0; i < length; i++)
		unknown[i]='*';
	unknown[i]='\0';
}
