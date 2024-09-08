#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESS_LIMIT 100
#define SMART_GUESS_PROBABILITY 80

/*
 * Program: Number Guessing Game
 * Description: This program plays a number guessing game where the computer tries to guess the user's number.
 *              The user responds with hints until the correct number is guessed.
 * Student: amohame2
 */

// Run
int playGuessingGame(int startingLowerBound, int startingUpperBound);

int main() {
    int result = playGuessingGame(1, MAX_GUESS_LIMIT);
    return result;
}

/*
 * Params:
 *   startingLowerBound - The initial lower bound for the guess range.
 *   startingUpperBound - The initial upper bound for the guess range.
 * Return:
 *   0 for normal exit, 1 for error due to inconsistent input.
 */

 int playGuessingGame(int startingLowerBound, int startingUpperBound) {
    int currentLowerBound = startingLowerBound, currentUpperBound = startingUpperBound;
    int computerGuess;
    char userFeedback;

    srand(time(NULL)); // Seed 

    while (1) {
        if (rand() % 100 < SMART_GUESS_PROBABILITY) {
            computerGuess = currentLowerBound + (currentUpperBound - currentLowerBound) / 2;
        } else {
            computerGuess = currentLowerBound + (rand() % (currentUpperBound - currentLowerBound));
        }

        printf("I guess %d. Enter 'H' if higher, 'L' if lower, '=' if correct:\n", computerGuess);

        // validation loop
        do {
            scanf(" %c", &userFeedback);
            while (getchar() != '\n'); // Flush buffer

            if (userFeedback != 'H' && userFeedback != 'L' && userFeedback != '=') {
                printf("Invalid entry '%c'. Please re-enter H, L, or =\n", userFeedback);
                userFeedback = '\0'; // Reset 
            }
        } while (userFeedback == '\0');

        // check to adjust bounds
        if (userFeedback == '=') {
            printf("Got it right with %d!\n", computerGuess);
            break;
        } else if (userFeedback == 'H') {
            if (computerGuess >= currentUpperBound) {
                currentLowerBound = currentUpperBound;
            } else {
                currentLowerBound = computerGuess + 1;
            }
        } else if (userFeedback == 'L') {
            if (computerGuess <= currentLowerBound) {
                currentUpperBound = currentLowerBound;
            } else {
                currentUpperBound = computerGuess - 1;
            }
        }

        // Check for inconsistent
        if (currentLowerBound > currentUpperBound) {
            printf("Inconsistent inputs. Exiting program.\n");
            return 1; 
        }
    }

    return 0;
}


