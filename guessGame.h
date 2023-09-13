#ifndef MAIN_H
#define MAIN_H

#define GUESS_LIMIT 6
#define HINT -1
#define ANSWER 70
#define MIN -1
#define MAX 100

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/**
 * hint - hint for the user
 * Return: void (Nothing);
 */
void hint(void);

/**
 * getGuess - collects user guess
 * Return: guess of the user
 */
int getGuess(void);

/**
 * answer - the answer for the guess game
 * Return: 68 as the answer
 */
int answer(void);



/**
 * checkingGuess - validate the user guess
 *
 * @round: keeps track of the rounds
 * @guessCount: the guess count
 *
 * Return: answer if user guesses right
 * otherwise 0 if guess count reaches limit
 */
int checkingGuess(int guessCount, int round);

/**
 * guessIsEqualToLimit - this function checks if the guess count
 * has reached it limit
 *
 * @guessCount: keeps count of the number of times the user has guessed
 *
 * Return: 1, if the guess count is equal to guess limit
 * and user plays again, otherwise 0, and exit if user does not
 */
int guessIsEqualToLimit(int guessCount);

/**
 * validateGuess - validates guess from the user
 *
 * @guess: the guess from the user
 *
 * Return: 1 if the user guessed it right, otherwise 0.
 * exit if the user
 */
int validateGuess(int guess);

#endif /*MAIN_H*/
