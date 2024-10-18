#include "games.h"
//Help from Steven Tran
//flips coin to see who goes first
int FlipCoin() {
    srand(time(0));
    return (rand() % 2);
}

bool boardFull(vector<char>& board) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            return false;
        }
    }
    return true;
}

void displayBoard(vector<char>& board) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            cout << i + 1 << " ";
        }
        else {
            cout << board[i] << " ";
        }
        if ((i + 1) % 3 == 0) {
            cout << endl;
        }
    }
}

char checkEndGame(vector<char>& board) {
    // check rows
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == board[i + 1] && board[i + 1] == board[i + 2] && board[i] != ' ') {
            return board[i];
        }
    }
    // check columns
    for (int i = 0; i < 3; i++) {
        if (board[i] == board[i + 3] && board[i + 3] == board[i + 6] && board[i] != ' ') {
            return board[i];
        }
    }
    // check diagonals
    if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ') {
        return board[0];
    }
    if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ') {
        return board[2];
    }
    // check if game is a draw
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            return ' ';
        }
    }
    return 'D';
}

int playerWin(vector<char>& board, char symbol) {
    // check rows
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == symbol && board[i + 1] == symbol && board[i + 2] == ' ') {
            return i + 2;
        }
        if (board[i] == symbol && board[i + 2] == symbol && board[i + 1] == ' ') {
            return i + 1;
        }
        if (board[i + 1] == symbol && board[i + 2] == symbol && board[i] == ' ') {
            return i;
        }
    }
    // check columns
    for (int i = 0; i < 3; i++) {
        if (board[i] == symbol && board[i + 3] == symbol && board[i + 6] == ' ') {
            return i + 6;
        }
        if (board[i] == symbol && board[i + 6] == symbol && board[i + 3] == ' ') {
            return i + 3;
        }
        if (board[i + 3] == symbol && board[i + 6] == symbol && board[i] == ' ') {
            return i;
        }
    }
    // check diagonals
    if (board[0] == symbol && board[4] == symbol && board[8] == ' ') {
        return 8;
    }
    if (board[0] == symbol && board[8] == symbol && board[4] == ' ') {
        return 4;
    }
    if (board[4] == symbol && board[8] == symbol && board[0] == ' ') {
        return 0;
    }
    if (board[2] == symbol && board[4] == symbol && board[6] == ' ') {
        return 6;
    }
    if (board[2] == symbol && board[6] == symbol && board[4] == ' ') {
        return 4;
    }
    if (board[4] == symbol && board[6] == symbol && board[2] == ' ') {
        return 2;
    }
    return -1;
}

int isCenterOpen(vector<char>& board) {
    if (board[4] == ' ') {
        return 4;
    }
    return -1;
}

// function for machinerule3 
int Corners(vector<char>& board, char playerSymbol, char machineSymbol) {
    if (board[0] == playerSymbol && board[8] == ' ') {
        return 8;
    }
    if (board[2] == playerSymbol && board[6] == ' ') {
        return 6;
    }
    if (board[6] == playerSymbol && board[2] == ' ') {
        return 2;
    }
    if (board[8] == playerSymbol && board[0] == ' ') {
        return 0;
    }
    return -1;
}

// function for machineRule4
int anyCorner(vector<char>& board) {
    if (board[0] == ' ') {
        return 0;
    }
    if (board[2] == ' ') {
        return 2;
    }
    if (board[6] == ' ') {
        return 6;
    }
    if (board[8] == ' ') {
        return 8;
    }
    return -1;
}

//function for machineRule5
int fillAnySpace(vector<char>& board) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            return i;
        }
    }
    return -1;
}

int computerMove(vector<char>& board, char computerSymbol, char playerSymbol) {
    int position;
    position = playerWin(board, computerSymbol);
    if (position != -1) {
        return position;
    }
    position = playerWin(board, playerSymbol);
    if (position != -1) {
        return position;
    }
    position = isCenterOpen(board);
    if (position != -1) {
        return position;
    }
    position = Corners(board, playerSymbol, computerSymbol);
    if (position != -1) {
        return position;
    }
    position = anyCorner(board);
    if (position != -1) {
        return position;
    }
    position = fillAnySpace(board);
    return position;
}

int playerMove(vector<char>& board) {
    int move;
    while (true) {
        cout << "Enter your move (1-9): ";
        cin >> move;
        move--; // adjust for 0-based indexing of board vector
        if (move < 0 || move > 8) { // check for valid move
            cout << "Invalid move. Try again." << endl;
            continue;
        }
        if (board[move] != ' ') { // check if position is already occupied
            cout << "Position already occupied. Try again." << endl;
            continue;
        }
        break;
    }
    return move;
}

// function to check if a player has won the game
bool checkWin(vector<char>& board, char playerSymbol) {
    // check rows
    for (int i = 0; i <= 6; i += 3) {
        if (board[i] == playerSymbol && board[i + 1] == playerSymbol && board[i + 2] == playerSymbol) {
            return true;
        }
    }
    // check columns
    for (int i = 0; i <= 2; i++) {
        if (board[i] == playerSymbol && board[i + 3] == playerSymbol && board[i + 6] == playerSymbol) {
            return true;
        }
    }
    // check diagonals
    if (board[0] == playerSymbol && board[4] == playerSymbol && board[8] == playerSymbol) {
        return true;
    }
    if (board[2] == playerSymbol && board[4] == playerSymbol && board[6] == playerSymbol) {
        return true;
    }
    return false;
}

void TicTacToe() {
    vector<char> board(9, ' ');
    char computerSymbol = 'O';
    char playerSymbol = 'X';
    int coin = rand() % 2;

    // print the board
    cout << "Initial board: " << endl;
    displayBoard(board);

    while (true) {
        if (coin == 0) {
            // machine goes first
            cout << "Computer's turn:\n";
            int position = computerMove(board, computerSymbol, playerSymbol);
            if (position == -1) {
                cout << "Game is a draw." << endl;
                return;
            }
            board[position] = computerSymbol;
            displayBoard(board);
            if (checkWin(board, computerSymbol)) {
                cout << "Computer wins!" << endl;
                return;
            }
            if (boardFull(board)) {
                cout << "Game is a draw." << endl;
                return;
            }
            // player's turn
            cout << "Player's turn:\n";
            position = playerMove(board);
            board[position] = playerSymbol;
            displayBoard(board);
            if (checkWin(board, playerSymbol)) {
                cout << "Player wins!" << endl;
                return;
            }
            if (boardFull(board)) {
                cout << "\nGame is a draw." << endl;
                return;
            }
        }
        else {
            // player goes first
            cout << "Player's turn:\n";
            int position = playerMove(board);
            board[position] = playerSymbol;
            displayBoard(board);
            if (checkWin(board, playerSymbol)) {
                cout << "Player wins!" << endl;
                return;
            }
            if (boardFull(board)) {
                cout << "Game is a draw." << endl;
                return;
            }
            // machine's turn
            cout << "Computer's turn:\n";
            position = computerMove(board, computerSymbol, playerSymbol);
            if (position == -1) {
                cout << "Game is a draw." << endl;
                return;
            }
            board[position] = computerSymbol;
            displayBoard(board);
            if (checkWin(board, computerSymbol)) {
                cout << "Computer wins!" << endl;
                return;
            }
            if (boardFull(board)) {
                cout << "Game is a draw." << endl;
                return;
            }
        }
    }
}