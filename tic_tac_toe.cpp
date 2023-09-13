/*
Task 3: TIC-TAC-TOE GAME 
Details: Build a simple console-based Tic-Tac-Toe game that allows two players to play against each other.
Game Board: Create a 3x3 grid as the game board.
Players: Assign "X" and "O" to two players.
Display Board: Show the current state of the board.
Player Input: Prompt the current player to enter their move.
Update Board: Update the game board with the player's move.
Check for Win: Check if the current player has won.
Check for Draw: Determine if the game is a draw.
Switch Players: Alternate turns between "X" and "O" players.
Display Result: Show the result of the game (win, draw, or ongoing).
Play Again: Ask if the players want to play another game.

Intern name: Imam Hasan
Intern ID:CS07WX36582
*/
#include <iostream>
using namespace std;

char board[3][3]; // 3x3 game board

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
}

bool checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true; 
}

int main() {
    char currentPlayer = 'X';
    bool gameOver = false;

    initializeBoard();

    while (!gameOver) {
        displayBoard();
        int row, col;
        cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2): ";
        cin >> row >> col;
        
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(currentPlayer)) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        } else if (checkDraw()) {
            displayBoard();
            cout << "It's a draw!" << endl;
            gameOver = true;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

