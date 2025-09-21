#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cctype>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    char playAgain = 'Y';

    cout << "   Welcome, to the Guess Game!\n";
    cout << "   Let's guess between (1-100). \n";

    while (toupper(playAgain) == 'Y') {
        int secretNumber = rand() % 100 + 1;
        int guess = 0;
        int attempts = 0;

        while (true) {
            cout << "Enter your guess: ";
            if (!(cin >> guess)) {
                cout << "Please enter a valid integer.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            attempts++;
            if (guess > secretNumber) {
                cout << "Too high,try again.\n";
            } else if (guess < secretNumber) {
                cout << "Too low,try again.\n";
            } else {
                cout << "Awesome, That's the correct number. " << attempts << " attempts.\n";
                break;
            }
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << '\n';
    }

    cout << "Thanks for playing. See you next time.\n";
    return 0;
}

