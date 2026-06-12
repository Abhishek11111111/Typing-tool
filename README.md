# Typing Speed Test Game in C

A console-based Typing Speed Test Game developed in C using multithreading (`pthread`). The application allows users to test their typing speed and accuracy by typing randomly selected quotes across different difficulty levels.

## Features

* Easy, Medium, and Hard difficulty modes
* Random quote generation
* 60-second timer using POSIX threads
* Typing accuracy calculation
* Time tracking
* Console-based user interface
* Lightweight and easy to run

## Technologies Used

* C Programming Language
* POSIX Threads (pthread)
* Standard C Libraries
* GCC Compiler

## How It Works

1. Select a difficulty level.
2. A random quote is displayed.
3. Type the displayed text as accurately as possible.
4. The program calculates:

   * Typing Accuracy (%)
   * Time Taken (seconds)
5. View your results and choose to play again.

## Compilation

```bash
gcc typing_game.c -o typing_game -pthread
```

## Run

```bash
./typing_game
```

## Learning Outcomes

This project helped in understanding:

* Multithreading in C
* String manipulation
* User input handling
* Randomization techniques
* Console application development
* Performance and accuracy calculations

## Future Improvements

* Real-time WPM calculation
* Leaderboard system
* Colored terminal interface
* User profiles
* File-based score storage
* Better accuracy and error tracking

## Author

Abhishek Bisht
Salesforce Commerce Cloud Developer | C Programming Enthusiast
