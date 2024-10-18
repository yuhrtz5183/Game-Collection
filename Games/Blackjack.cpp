#include "games.h"
// Help from Aymen Abood
struct card {
    string suite;
    int face;
};

vector<card> CreateDeck() {
    vector<card> deck;
    string suites[4];
    card tempCard;
    for (int s = 0; s < 4; s++) {
        tempCard.suite = suites[s];
        for (int f = 0; f < 13; f++) {
            tempCard.face = f;
            if (tempCard.face == 0)
                tempCard.face = 1;
            deck.push_back(tempCard);
        }
    }
    return deck;
}

int handTotal(vector<card> hand) {
    int total = 0;
    bool hasAce = false;
    for (int i = 0; i < hand.size(); ++i) {
        if (hand.at(i).face == 11 || hand.at(i).face == 12 ||
            hand.at(i).face == 13) {
            total += 10;
        }
        else if (hand.at(i).face == 1) {
            if (total + 11 > 21) {
                total += 1;
            }
            else {
                total += 11;
                hasAce = true;
            }
        }
        else {
            total += hand.at(i).face;
        }
    }
    cout << setw(20) << "TOTAL: " << total << endl << endl;
    return total;
}

void shuffle(vector<card>& deck) {
    srand(time(NULL));
    int randomPos;
    for (int i = 0; i < 52; ++i) {
        randomPos = (rand() % (52 - i)) + i;
        if (randomPos == 0)
            randomPos = 1;
        swap(deck[i],
            deck[randomPos]);
    }
}

void display(vector<card> hand) {
    for (int i = 0; i < hand.size(); ++i) {
        if (hand.at(i).face == 1) {
            cout << hand.at(i).suite << setw(3) << "A" << endl;
        }
        else if (hand.at(i).face == 11) {
            cout << hand.at(i).suite << setw(3) << "J" << endl;
        }
        else if (hand.at(i).face == 12) {
            cout << hand.at(i).suite << setw(3) << "Q" << endl;
        }
        else if (hand.at(i).face == 13) {
            cout << hand.at(i).suite << setw(3) << "K" << endl;
        }
        else {
            cout << hand.at(i).suite << setw(3) << hand.at(i).face << endl;
        }
    }
}

void deal(vector<card>& hand, vector<card>& deck) {
    hand.push_back(deck.at(0));
    deck.erase(deck.begin());
}

void Blackjack() {
    cout << "WELCOME TO BLACKJACK\n\n" << endl;
    vector<card> deck = CreateDeck();
    vector<card> playerHand, computerHand;
    char choice;
    int playerTotal, computerTotal;
    shuffle(deck);

    for (int i = 0; i < 2; ++i) {
        deal(playerHand, deck);
        deal(computerHand, deck);
    }

    cout << "Player has the following cards" << endl;
    display(playerHand);
    playerTotal = handTotal(playerHand);

    cout << "Would you like to take another card? Y or N ";
    cin >> choice;
    while (true) {
        if (toupper(choice) == 'Y') {
            deal(playerHand, deck);
            cout << "\nPlayer has the following cards:" << endl;
            display(playerHand);
            playerTotal = handTotal(playerHand);
            if (playerTotal > 21) {
                cout << "OOPS - the Player went over 21. COMPUTER WINS!" << endl;
                break;
            }
            else {
                cout << "Would you like to take another card? Y or N ";
                cin >> choice;
                continue;
            }
        }
        else if (toupper(choice) == 'N') {
            cout << "\nComputer has the following cards:" << endl;
            display(computerHand);
            computerTotal = handTotal(computerHand);

            while (computerTotal <= 17) {
                deal(computerHand, deck);
                cout << "\nComputer has the following cards:" << endl;
                display(computerHand);
                computerTotal = handTotal(computerHand);
                if (computerTotal > 21) {
                    cout << setw(30) << "*****PLAYER WINS!!!*****" << endl;
                    return; // End game if computer goes over 21
                }
            }

            // Determine winner
            if (playerTotal > computerTotal) {
                cout << setw(30) << "*****PLAYER WINS!!!*****" << endl;
                break;
            }
            else if (computerTotal > playerTotal) {
                cout << setw(30) << "OOPS! COMPUTER WINS!!" << endl;
                break;
            }
            else {
                cout << setw(20) << "TIE!!!" << endl;
                break;
            }
        }
        else {
            cout << "Invalid input. Please enter Y or N: ";
            cin >> choice;
        }
    }
}