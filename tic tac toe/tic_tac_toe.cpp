#include <iostream>
using namespace std;

char board[3][3];  
char currentPlayer = 'X';


void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}


void printBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}


bool checkWin() {
  
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }
 
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
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

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    initializeBoard();
    bool gameover = false;

    cout << "Welcome to Tic Tac Toe!\n";
    printBoard();

    while (!gameover) {
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column 1-3): ";
        cin >> row >> col;

       
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
            cout << "Invalid move! Try again.\n";
            continue;
        }

      
        board[row-1][col-1] = currentPlayer;
        printBoard();

       
        if (checkWin()) {
            cout << "Player " << currentPlayer << " wins!\n";
            gameover = true;
        }
       
        else if (checkDraw()) {
            cout << "It's a draw!\n";
            gameover = true;
        } else {
            switchPlayer();
        }
    }

    return 0;
}
