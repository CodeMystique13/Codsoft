//tic-tac-toe game
#include <iostream>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    cout << "Current Board:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n---------\n";
    }
    cout << endl;
}

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; // Row check
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; // Column check
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true; // Diagonal 1
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true; // Diagonal 2
    return false;
}

// Function to check if the game is a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

// Function to switch between players
char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to play the game
void playGame() {
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}; // Initialize board with numbers
    char currentPlayer = 'X';
    int move;
    bool gameOngoing = true;

    while (gameOngoing) {
        displayBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        // Update the board with the player's move
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;
        
        if (move >= 1 && move <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = currentPlayer;

            // Check if the current player has won
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOngoing = false;
            }
            // Check if the game is a draw
            else if (checkDraw(board)) {
                displayBoard(board);
                cout << "The game is a draw!" << endl;
                gameOngoing = false;
            }
            else {
                // Switch to the other player
                currentPlayer = switchPlayer(currentPlayer);
            }
        } else {
            cout << "Invalid move! Try again.\n";
        }
    }
}

int main() {
    char playAgain = 'Y';

    // Loop to play multiple games if desired
    do {
        playGame();
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thanks for playing!" << endl;
    return 0;
}