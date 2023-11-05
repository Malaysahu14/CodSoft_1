#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0));  // Seed the random number generator with the current time
    int lowerLimit = 1;  // Lower bound of the range
    int upperLimit = 100;  // Upper bound of the range
    int secretNumber = rand() % (upperLimit - lowerLimit + 1) + lowerLimit;
    int attempts = 0;
    int guess;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between " << lowerLimit << " and " << upperLimit << "." << endl;

    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < lowerLimit || guess > upperLimit) {
            cout << "Please guess a number within the valid range." << endl;
        } else if (guess < secretNumber) {
            cout << "Too low. Try again." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high. Try again." << endl;
        } else {
            cout << "Congratulations! You've guessed the number in " << attempts << " attempts." << endl;
            break;
        }
    }

    return 0;
}
