#include "guessGame.h"

/**
 * hint - hint for the user
 * Return: void (Nothing);
 */
void hint(void)
{
	printf("\nThe number is between 1 - 100 and it an even number\n"
		"but the first digit is an even number\n");
}

/**
 * answer - the answer for the guess game
 * Return: 68 as the answer
 */
int answer(void)
{
	return (ANSWER);
}

/**
 * getGuess - collects user guess
 * Return: guess of the user
 */
int getGuess(void)
{
	int guess;

	printf("\nEnter your guess\n");
	scanf("%d", &guess);
	/*calling the hint function*/
	if (guess == HINT)
	{
		hint();
		return (getGuess());
	}
	/*return the guess*/
	return (guess);
}

/**
 * checkingGuess - validate the user guess
 *
 * @round: keeps track of the rounds
 * @guessCount: the guess count
 *
 * Return: answer if user guesses right
 * otherwise 0 if guess count reaches limit
 */
int checkingGuess(int guessCount, int round)
{
	char choice;
	int guess;

	guess = getGuess();
	/*base case: guess should be in the range of -1 - 100*/
	if (guess < MIN || guess > MAX)
	{
		printf("\nExiting........\nnot in range 1 - 100\n");
		exit(1);
	}
	/*
	* check if guess is equal to answer and call checkingGuess function,
	* if the user want to move on to the next round.
	*/
	if (validateGuess(guess))
	{
		printf("round (%d)\n", round + 1);
		guessCount = 1;
		return (checkingGuess(guessCount, round + 1));
	}
	/*
	 * check if guess is equal to limit
	 * and call the checkingGuess function recursively if the user
	 * wants to play again.
	 */
	if (guessIsEqualToLimit(guessCount))
	{
		guessCount = 1;
		return (checkingGuess(guessCount, round));
	}
	 /*guess is greater or less, or equal to answer*/
	if (guess >= answer())
		printf("\n%d is greater than the answer, try again\n", guess);
	else
		printf("\n%d is lower than the answer, try again\n", guess);
	/*current guess status*/
	printf("%d out of %d guess\n", guessCount, GUESS_LIMIT);
	return (checkingGuess(guessCount + 1, round));/*call, not case is met*/
}

/**
 * guessIsEqualToLimit - this function checks if the guess count
 * has reached it limit
 *
 * @guessCount: keeps count of the number of times the user has guessed
 *
 * Return: 1, if the guess count is equal to guess limit
 * and user plays again, otherwise 0, and exit if user does not
 */
int guessIsEqualToLimit(int guessCount)
{
	char choice;

	/*return, if the number of guesses reaches the limit*/
	if (guessCount == GUESS_LIMIT)
	{
		printf("\n6 out of 6 guess\nOops!");
		printf("\nguess has reached it limit");

		printf("\nDo you want to play again (y or n)\n");
		scanf(" %c", &choice);

		choice = tolower(choice);/*incase the user capitalises the letter*/
		/*ask user if the want to play again, hence return 1 if true*/
		switch (choice)
		{
			case 'y':
				return (1);
			case 'n':
				printf("Thanks for playing,");
				printf("You will pass this round very soon\n");
				exit(0); /*exit don't return*/
				break;
			default:
				printf("\ninvalid choice,");
				printf("please enter 'y' or 'n'");
				guessIsEqualToLimit(guessCount);
				exit(0);
				break;
		}
	}
	else
		return (0); /*return 0, if false*/
}

/**
 * validateGuess - validates guess from the user
 *
 * @guess: the guess from the user
 *
 * Return: 1 if the user guessed it right, otherwise 0.
 * exit if the user
 */
int validateGuess(int guess)
{
	char choice;

	/*return, if the user guessed it right*/
	if (guess == answer())
	{
		printf("\t\tHey!, congratulations!!!🎉🥳\n"
		"\t\tyou have guessed the right number %d🎉🥳\n", guess);

		printf("Do you want to play another round (y or n)\n");
		scanf(" %c", &choice);
		/*
		 * ask user if they want to play another round
		 * hence return 1 if true
		 */

		choice = tolower(choice);/*incase the user capitalises the letter*/
		switch (choice)
		{
			case 'y':
				return (1);
			case 'n':
				puts("That was a good run, Thanks for playing");
				exit(0); /*exit don't return*/
				break;
			default:
				puts("\ninvalid choice, please enter 'y' or 'n'");
				validateGuess(guess);
				exit(0);
				break;
		}
	}
	else
		return (0); /*return if false*/
}

