#include "guessGame.h"
/**
 * main - Entry point for the program
 * Return: 0 (Success);
 */
int main(void)
{
	int guessCount, round, i, score;

	/*prompt*/
	puts("Hi thanks, for joining the guess game!");
	puts("In this game you have 6 trials to get the right number");
	puts("Your guess shoud be within the range of 1 - 100");
	printf("A hint will be shown to you to know if your guess ");
	printf("is less than or greater than the answer, so watch out👀\n");
	puts("Enter -1 to see more hint, note this can be used once for each round");
	puts("Are you ready? Let go!💪💪");

	for (i = 1; i <= 2; i++)
		printf("↓↓↓↓↓↓↓↓\n");
	printf("round (1)\n");

	guessCount = 1, round = 1, score = 0;
	checkingGuess(&guessCount, round, score);

	return (0);
}
