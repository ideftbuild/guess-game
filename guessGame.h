#ifndef MAIN_H
#define MAIN_H

#define GUESS_LIMIT 6
#define HINT -1
#define MIN 1
#define MAX 100

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

/**
 * hint - hint for the user
 * @answer: generated answer
 * Return: void (Nothing);
 */
void hint(int answer);

/**
 * getGuess - collects user guess
 * Return: guess of the user
 */
int getGuess(void);

/**
 * generate_answer - the answer for the guess game
 * Return: 68 as the generate_answer
 */
int generate_answer(void);

/**
 * checkingGuess - validate the user guess
 *
 * @guessCount: the guess count
 * @round: current round
 * @score: current score
 *
 * Return: answer if user guesses right
 * otherwise 0 if guess count reaches limit
 */
void checkingGuess(int *guessCount, int round, int score);

/**
 * guessIsEqualToLimit - this function checks if the guess count
 * has reached it limit
 *
 * @guessCount: keeps count of the number of times the user has guessed
 * @score: current score accumulated
 *
 * Return: 1, if the guess count is equal to guess limit and user plays again
 * otherwise 0, and exit if user quits
 */
int guessIsEqualToLimit(int guessCount, int *score);

/**
 * validateGuess - validates guess from the user
 *
 * @guess: the guess from the user
 * @score: the total score accumulated
 * @answer: the random generated answer
 *
 * Return: 1 if the user guessed it right, otherwise 0.
 * exit if the user
 */
int validateGuess(int guess, int *score, int answer);

#endif /*MAIN_H*/
