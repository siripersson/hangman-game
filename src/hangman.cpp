//============================================================================
// Name        : Hangman_game.cpp
// Author      : Siri Persson
// Version     : 1
// Copyright   : Your copyright notice
// Description : Hangman game in C++
//============================================================================
#include "hangman.h"

int main (){
	startHangmanGame();
	return 0;
}

void startHangmanGame () {
	std::string playername;
	std::string already_guessed_letters;
	int number_of_tries = 0;
	int random_number;
	bool alreadyGuessedLetter;
	bool alphabeticalLetter;
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

	random_number = getRandomNumber();
	strcpy(word, allWords[random_number]);

	initializeUnknownWordWithStars(word, unknown_word);
	welcomeTheUser(playername);

	while (number_of_tries < MAX_TRIES) {
		guessed_letter= getGuessedLetterFromUser(unknown_word);
		alreadyGuessedLetter = checkIfAlreadyGuessedLetter(guessed_letter, already_guessed_letters);
		alphabeticalLetter = isAlphabeticalLetter(guessed_letter);

		if (alreadyGuessedLetter)
		{
			cout << endl << "You have already guessed this letter. Try again!" << endl;
			displayNumberOfTriesLeft(number_of_tries);
			displayAlreadyGuessedLetters (already_guessed_letters);
		}

		if( !alphabeticalLetter)
		{
			cout << endl << "You must enter an alphabetical letter. Try again!" << endl;
			displayNumberOfTriesLeft(number_of_tries);
			displayAlreadyGuessedLetters (already_guessed_letters);
		}

		else if ( !alreadyGuessedLetter )
		{
			already_guessed_letters = already_guessed_letters + guessed_letter + " ";
			number_of_tries++;
		}

		if ( letterFill(guessed_letter, word, unknown_word) == 0  && alphabeticalLetter && !alreadyGuessedLetter )
		{
			cout << endl << "Whoops! That letter isn't in there!" << endl;
			displayNumberOfTriesLeft( number_of_tries );
			displayAlreadyGuessedLetters ( already_guessed_letters );
		}
		else if ( alphabeticalLetter && !alreadyGuessedLetter )
		{
			cout << endl << "You found a letter! Isn't that exciting!" << endl;
			if ( strcmp( word, unknown_word ) == 0)
			{
				cout << word << endl;
				cout << "\nCongratulations " << playername <<", you won the game!" << endl;
				break;
			}
			else
			{
				displayNumberOfTriesLeft( number_of_tries );
				displayAlreadyGuessedLetters ( already_guessed_letters );
			}
		}
		if ( number_of_tries == MAX_TRIES && alphabeticalLetter && !alreadyGuessedLetter )
		{
			cout << "\nSorry " << playername << ", you lose...you've been hanged." << endl;
			cout << "The word was : " << word << endl;
			break;
		}
	}
	getch(); // måste ha denna annars funkar inte inläggningen av gissningar
}

int getRandomNumber()
{
	srand( time(NULL) );
	int random_number = rand() % 10 + 1;
	return random_number;
}

void welcomeTheUser( std::string playername )
{
	cout << "\nType your name: " << endl;
	cin >> playername;
	cout << "\nWelcome " << playername << " to this awesome Hangman game!" << endl;
	cout << "Guess a country name."<< endl;
	cout << "Each letter is represented by a star. You have to type only one letter in one try"<< endl;
	cout << "You have " << MAX_TRIES << " tries to try and guess the word"<< endl;
}

char getGuessedLetterFromUser( char unknown_word [] )
{
	char guessed_letter;
	cout << unknown_word << endl;
	cout << "\nGuess a letter: " << endl;
	cin >> guessed_letter;
	return tolower( guessed_letter );
}

bool checkIfAlreadyGuessedLetter( char guessed_letter, std::string already_guessed_letters )
{
	std::string string_letter;
	stringstream ss;
	std::size_t found;
	ss << guessed_letter;
	ss >> string_letter;
	found = already_guessed_letters.find( string_letter );
	return found != std::string::npos;
}

bool isAlphabeticalLetter( char guessed_letter )
{
	return isalpha( guessed_letter ) != 0;
}

void displayNumberOfTriesLeft( int number_of_tries )
{
	cout << "You have " << MAX_TRIES - number_of_tries << " guesses left." << endl;
}

void displayAlreadyGuessedLetters( std::string already_guessed_letters )
{
	cout << "Already guessed letters: " << already_guessed_letters << endl;
}

void incrementNumberOfTriesAndAlreadyGuesssedLetters( char guessed_letter, std::string already_guessed_letters, int number_of_tries )
{
	already_guessed_letters = already_guessed_letters + guessed_letter + " ";
	number_of_tries++;
}

void initializeUnknownWordWithStars( char word[], char unknown_word[] )
{
	int i;
	int wordlength = strlen( word );
	for( i = 0; i < wordlength; i++ )
		unknown_word[i] = '*';
	unknown_word[i] = '\0';
}

int letterFill( char guess, char secretword[], char guessword[] )
{
	int matches=0;
	for( int i = 0; secretword[i] != '\0'; i++ ) {
		if ( guess == secretword[i] ) {
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}
