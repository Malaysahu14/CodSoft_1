#include <iostream>
#include <vector>

using namespace std;

// Function to draw the Tic-Tac-Toe board
void drawBoard(const vector<char>& board) {
    system("clear");  // Use "cls" for Windows
    cout << "Tic-Tac-Toe Game\n\n";
    for (int i = 0; i < 9; i++) {
        cout << " " << board[i] << " ";
        if (i % 3 == 2) {
            cout << endl;
            if (i < 8) cout << "-----------\n";
        } else {
            cout << "|";
        }
    }
    cout << endl;
}

// Function to check if the game is over (win or draw)
bool isGameOver(const vector<char>& board) {
    // Check for a win
    for (int i = 0; i < 8; i++) {
        const int a = i / 3;
        const int b = i % 3;
        if (board[a * 3 + b] != ' ' && board[a * 3 + b] == board[a * 3 + b + 1] && board[a * 3 + b] == board[a * 3 + b + 2]) {
            return true; // Horizontal win
        }
        if (board[b] != ' ' && board[b] == board[b + 3] && board[b] == board[b + 6]) {
            return true; // Vertical win
        }
    }
    if ((board[0] != ' ' && board[0] == board[4] && board[0] == board[8]) ||
        (board[2] != ' ' && board[2] == board[4] && board[2] == board[6])) {
        return true; // Diagonal win
    }
    // Check for a draw
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            return false; // The game is not over
        }
    }
    return true; // It's a draw
}

int main() {
    vector<char> board(9, ' ');
    char player = 'X';
    int cell;

    while (true) {
        drawBoard(board);
        cout << "Player " << player << ", enter a cell (1-9): ";
        cin >> cell;
        if (cell < 1 || cell > 9 || board[cell - 1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }
        board[cell - 1] = player;

        if (isGameOver(board)) {
            drawBoard(board);
            if (isGameOver(board) && !isGameOver(board)) {
                cout << "Player " << player << " wins!" << endl;
            } else {
                cout << "It's a draw!" << endl;
            }
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
