#include "guessGame.h"
/**
 * main - Entry point for the program
 * Return: 0 (Success);
 */
int main(void)
{
	int guessCount, round, i;

	/*prompt*/
	puts("Hi thanks, for joining the guess game!");
	puts("In this game you have 6 trials to get the right number");
	puts("Your guess shoud be within the range of 1 - 100");
	puts("Enter -1 for hint");
	puts("Are you ready? Let go!💪💪");

	for (i = 1; i <= 2; i++)
		printf("↓↓↓↓↓↓↓↓\n");
	printf("round (1)\n");

	guessCount = 1, round = 1;
	checkingGuess(guessCount, round);
	return (0);
}
