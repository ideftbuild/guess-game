#include "guessGame.h"

/**
 * hint - hint for the user
 * @answer: generated answer
 * Return: void (Nothing);
 */
void hint(int answer)
{
	printf("last digit is : %d\n", answer % 10);
	puts("-1 is not for hint anymore");
}

/**
 * generate_answer - generates a random answer
 * Return: 68 as the answer
 */
int generate_answer(void)
{
	srand(time(NULL));
	return (rand() % MAX + MIN);
}

/**
 * getGuess - collects user guess
 * Return: guess of the user
 */
int getGuess(void)
{
	int guess;

	printf("\nEnter your guess\n:::: ");
	scanf("%d", &guess);
	/*return the guess*/
	return (guess);
}

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
void checkingGuess(int *guessCount, int round, int score)
{
	int guess, answer, hintCount, hintLimit;

	hintCount = 0, hintLimit = 1;
	answer = generate_answer();
	do {
		guess = getGuess();
		/*user can only use 1 hint*/
		if (guess == HINT && hintCount < hintLimit)
		{
			hintCount++, hint(answer);
			continue;
		}
		else if (guess == HINT && hintCount == hintLimit)
		{
			hintCount++;
			puts("haha no more hints, good luck");
			continue;
		}
		/*guess should be in the range of -1 - 100*/
		if (guess < MIN || guess > MAX)
		{
			printf("\nExiting........\nnot in range 1 - 100\n");
			exit(1);
		}
		/*loop will only execute if the user want to play again*/
		if (validateGuess(guess, &score, answer))
		{
			round++, *guessCount;
			printf("round (%d)\n", round);
			checkingGuess(guessCount, round, score);
		}
		/*loop will only execute if the user want to play again*/
		if (guessIsEqualToLimit(*guessCount, &score))
		{
			printf("round (%d)\n", round);
			*guessCount = 1;
			continue;
		}
		 /*guess is greater or less, or equal to answer*/
		if (guess >= answer)
			printf("\n%d is greater than the answer, try again\n", guess);
		else
			printf("\n%d is lower than the answer, try again\n", guess);
		/*current guess status*/
		printf("%d out of %d guess\n", *guessCount, GUESS_LIMIT);
		*guessCount += 1;
	} while (guess != answer || *guessCount != GUESS_LIMIT);
}

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
int guessIsEqualToLimit(int guessCount, int *score)
{
	char choice;
	/*return, if the number of guesses reaches the limit*/
	if (guessCount == GUESS_LIMIT)
	{
		printf("\n6 out of 6 guess\nOops!\n");
		printf("guess has reached it limit\n");

		printf("\nDo you want to play again (y or n)\n");
		scanf(" %c", &choice);
		/*incase the user capitalises the letter*/
		choice = tolower(choice);

		/*ask user if the want to play again, hence return 1 if true*/
		switch (choice)
		{
			case 'y':
				return (1);
			case 'n':
				printf("Final Score: %d, You will pass this round very soon\n", *score);
				exit(0); /*exit don't return*/
			default:
				printf("\ninvalid choice,");
				printf("please enter 'y' or 'n'");
				guessIsEqualToLimit(guessCount, score);
				exit(0); /*exit don't return*/
		}
	}
	else
		return (0); /*false*/
}

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
int validateGuess(int guess, int *score, int answer)
{
	char choice;
	int i;

	i = 0;
	/*return, if the user guessed it right*/
	if (guess == answer)
	{
		printf("\n\t\tHey!, congratulations!!!🎉🥳\n"
		"\t\tyou have guessed the right number %d🚀\n", guess);
		*score += 50;
		printf("\n\t\tScore---> %d <---Score\n\n", *score);

		do {
			printf("Do you want to play another round (y or n)\n");
			scanf(" %c", &choice);

			choice = tolower(choice);/*incase the user capitalises the letter*/
			switch (choice)
			{
				case 'y':
					return (1); /*return true to if*/
				case 'n':
					printf("Final Score -> %d, That was a good run", *score);
					exit(0); /*exit don't return*/
				default:
					if (i != 3)
					puts("\ninvalid choice, please enter 'y' or 'n'");
			}
		i++;
		} while (i <= 3);

		/*did not match 3 times, exit the program*/
		puts("Exiting......");
		exit(1);

	}
	else
		return (0); /*false*/
}

