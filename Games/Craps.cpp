#include "games.h"

void Craps() {
    double betWorth = 50;
    double bet;
    char playAgain{};
    int die1;
    int die2;
    int total;
    int newTotal;
    int point;

    cout << "Welcome to Craps!" << endl;

    while (toupper(playAgain) != 'N') {
        cout << "Your net worth is $" << setprecision(2) << fixed << betWorth << ". Please enter your bet: ";
        cin >> bet;
        while (bet > betWorth || bet <= 0) {
            cout << "Your net worth is only: $" << setprecision(2) << fixed << betWorth << ". Please adjust your bet: ";
            cin >> bet;
        }

        srand(time(0));
        die1 = rand() % 6 + 1;
        die2 = rand() % 6 + 1;
        total = die1 + die2;
        if (total == 7 || total == 11) {
            cout << "You rolled: " << die1 << " + " << die2 << " = " << total << "\nYou Win!!!" << endl;
            cout << endl;
            cout << endl;
            betWorth += bet;
        }
        else if (total == 2 || total == 3 || total == 12) {
            betWorth -= bet;
            cout << "You rolled " << die1 << " + " << die2 << " = " << total << "\nYou Lost!!! You now have: $" << setprecision(2) << fixed << betWorth << endl;
        }
        else {
            point = total;
            cout << "You rolled " << die1 << " + " << die2 << " = " << point << endl;
            cout << endl;
            cout << endl;
            cout << "     Point is : " << point << endl;
            die1 = rand() % 6 + 1;
            die2 = rand() % 6 + 1;
            newTotal = die1 + die2;
            while (newTotal != point && newTotal != 7) {
                die1 = rand() % 6 + 1;
                die2 = rand() % 6 + 1;
                newTotal = die1 + die2;
                cout << "     You rolled: " << die1 << " + " << die2 << " = " << newTotal << endl;
            }
            if (newTotal == point) {
                cout << "     Yay, you win!";
                cout << endl;
                cout << endl;
                betWorth += bet;
            }
            else {
                cout << "     Sorry, but you lost!!\n\n";
                betWorth -= bet;
            }
            if (betWorth <= 0) {
                cout << "\nSorry - you are out of money. Don't make us escort you out - that would be embarrassing!!" << endl;
                break;
            }
            cout << "\nWould you like to go again? (Y or N) ";
            cin >> playAgain;
        }
    }
}