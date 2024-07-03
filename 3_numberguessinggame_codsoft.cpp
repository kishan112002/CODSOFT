#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0)); // seed the random number generator
    int numberToGuess = rand() % 100 + 1; // generate a random number between 1 and 100
    int numberOfTries = 0;
    int guess;

    cout << "Welcome to the number guessing game!" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl;
    cout << "Try to guess it!" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        numberOfTries++;

        if (guess > numberToGuess) {
            cout << "Your guess is too high!" << endl;
        } else if (guess < numberToGuess) {
            cout << "Your guess is too low!" << endl;
        } else {
            cout << " Congratulations! You found the number in " << numberOfTries << " tries." << endl;
        }
    } while (guess != numberToGuess);

    return 0;
}