# GuessMyNumber-cLang

## Overview
This repository contains a C program that plays a reverse number guessing game. The computer attempts to guess a number that the user has in mind, based on the user's hints. The program is designed to handle valid and invalid inputs gracefully and terminates appropriately under inconsistent input scenarios.

## How to Compile and Run the Program

### Prerequisites
- You need to have a C compiler like GCC installed on your machine.
- Access to a terminal or command prompt.

### Compiling the Program
1. Open your terminal.
2. Navigate to the directory containing the `guess-number.c` file.
3. Compile the program using the following command:

`gcc guess-number.c -o guess-number`

### Running the Program
- After compiling, you can run the program by entering:

`./guess-number`


### How to Play
- The program will make a guess about the number you are thinking of between 1 and 100.
- Respond with:
- `H` if your number is higher than the computer's guess.
- `L` if your number is lower than the computer's guess.
- `=` if the computer's guess is correct.
- Continue to provide feedback until the computer guesses correctly.


## Authors
- Ahmed Mohamed | ahmdmshazly@gmail.com

