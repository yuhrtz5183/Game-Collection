#include "games.h"

void menu() {
    cout << "Games List" << endl;
    cout << "B - Blackjack" << endl;
    cout << "C - Craps" << endl;
    cout << "H - Hangman" << endl;
    cout << "T - TicTacToe" << endl;
    cout << "W - War" << endl;
    cout << "Q - Quit" << endl;
    cout << "What game would you like to play?" << endl;
}

int main() {
    menu();
    char userInput;

    cin >> userInput;

    while (toupper(userInput) != 'Q') {

        if (toupper(userInput) == 'B') {
            Blackjack();
        }
        else if (toupper(userInput) == 'C') {
            Craps();
        }
        else if (toupper(userInput) == 'H') {
            Hangman();
        }
        else if (toupper(userInput) == 'T') {
            TicTacToe();
        }
        else if (toupper(userInput) == 'W') {
            War();
        }
        else if (toupper(userInput) == 'Q') {
            break;
        }
        else {
            cout << "\nError Invalid Input" << endl;
        }

        cout << endl;
        menu();
        cin >> userInput;

    }

}