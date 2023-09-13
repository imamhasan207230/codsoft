/*
Task 1: NUMBER GUESSING GAME 
Details: Create a program that generates a random number and asks the user to guess it. Provide feedback on whether the guess is too high or too low until the user guesses the correct number.

Intern name: Imam Hasan
Intern ID:CS07WX36582
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(static_cast<unsigned>(time(0)));

    int randomNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;

    cout << "Welcome to the Guess the Number Game!" << endl;

    while (true) {
        cout << "Enter your guess (1-100): ";
        cin >> guess;

        if (guess < 1 || guess > 100) {
            cout << "Please enter a valid guess between 1 and 100." << endl;
            continue;
        }

        attempts++;

        if (guess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number " << randomNumber << " in " << attempts << " attempts." << endl;
            break; 
        }
    }

    return 0;
}

