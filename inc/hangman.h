
// include guard
#ifndef __MYCLASS_H_INCLUDED__
#define __MYCLASS_H_INCLUDED__

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
void createHangmanGame ();

#endif // __MYCLASS_H_INCLUDED__
