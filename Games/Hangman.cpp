#include "games.h"

void Hangman() {
    srand(time(NULL));
    int guessesLeft = 6;
    char guess;
    ifstream inFile;
    inFile.open("words.txt");
    if (!inFile.is_open()) {
        cout << "File does not open" << endl;
        exit(0);
    }
    string word;
    vector<string> inputList;
    int randomPick;
    while (inFile >> word) {
        inputList.push_back(word);
    }
    randomPick = rand() % (inputList.size());
    inFile.close();

    string secretWord = inputList[randomPick];
    string guessWord = secretWord;
    for (int i = 0; i < secretWord.length(); ++i) {
        guessWord[i] = '_';
    }

    cout << "HANGMAN - your word is: " << guessWord << endl;
    while (true) {
        cout << "\nEnter your guess: ";
        cin >> guess;

        if (secretWord.find(guess) != string::npos) {
            for (int i = 0; i < guessWord.length(); ++i) {
                if (secretWord[i] == guess) {
                    guessWord[i] = guess;
                }
            }
            cout << "Nice Guess! You have " << guessesLeft << " guesses left. Your current work: " << guessWord << endl;
            if (secretWord == guessWord) {
                cout << "\nNice Guess! You WIN!!!! The word was " << secretWord << endl;
                break;
            }
        }
        else {
            guessesLeft = guessesLeft - 1;
            cout << "Sorry! Guess is not valid. You have " << guessesLeft << " guesses left. Your current word: " << guessWord << endl;
        }
        if (guessesLeft == 0) {
            cout << "\nYou LOST!!!! The word was " << secretWord << endl;
            break;
        }
    }
}