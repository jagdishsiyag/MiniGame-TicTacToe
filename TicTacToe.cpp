/*  ============================================================
    TIC TAC TOE  (Console-based mini game in C++)
    ------------------------------------------------------------
    Concepts demonstrated:
        * 2D arrays        -> 3x3 board
        * Loops            -> rendering, input validation
        * Conditionals     -> win/loss/draw detection
        * Functions        -> modular game logic
        * Replay loop      -> do-while
    ============================================================ */

#include <iostream>
#include <limits>
#include <string>

using namespace std;

const int SIZE = 3;

/* ---------------- Board Helpers ---------------- */

void initBoard(char board[SIZE][SIZE]) {
    for (int r = 0; r < SIZE; ++r)
        for (int c = 0; c < SIZE; ++c)
            board[r][c] = ' ';
}

void displayBoard(const char board[SIZE][SIZE]) {
    cout << "\n";
    cout << "     Col 1   Col 2   Col 3\n";
    for (int r = 0; r < SIZE; ++r) {
        cout << "  Row " << (r + 1) << "  ";
        for (int c = 0; c < SIZE; ++c) {
            cout << "  " << board[r][c] << "  ";
            if (c < SIZE - 1) cout << "|";
        }
        cout << "\n";
        if (r < SIZE - 1) cout << "         -----+-----+-----\n";
    }
    cout << "\n";
}

/* ---------------- Move Validation ---------------- */

bool isValidMove(const char board[SIZE][SIZE], int r, int c) {
    return r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] == ' ';
}

/* ---------------- Win Detection ---------------- */

// Returns 'X' or 'O' if that player has won, otherwise ' '.
char checkWinner(const char board[SIZE][SIZE]) {
    // Rows & columns
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];

        if (board[0][i] != ' ' &&
            board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }

    // Diagonals
    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];

    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    return ' ';
}

// Board full = draw
bool isBoardFull(const char board[SIZE][SIZE]) {
    for (int r = 0; r < SIZE; ++r)
        for (int c = 0; c < SIZE; ++c)
            if (board[r][c] == ' ') return false;
    return true;
}

/* ---------------- Input Handling ---------------- */

int readInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "  [!] Invalid input. Enter a number.\n";
    }
}

/* ---------------- One Full Game ---------------- */

// Returns true if the user wants another round.
bool playOnce(int& xWins, int& oWins, int& draws) {
    char board[SIZE][SIZE];
    initBoard(board);

    char current = 'X';
    int  moves   = 0;
    char winner  = ' ';

    cout << "\n=== TIC TAC TOE ===\n";
    cout << "Player 1 = X   |   Player 2 = O\n";
    cout << "Enter row and column numbers (1-3) to place your mark.\n";

    while (true) {
        displayBoard(board);

        cout << "Player " << current << "'s turn.\n";
        int r = readInt("  Enter Row    (1-3) : ") - 1;
        int c = readInt("  Enter Column (1-3) : ") - 1;

        if (!isValidMove(board, r, c)) {
            cout << "  [!] Invalid move. Try again.\n";
            continue;
        }

        board[r][c] = current;
        ++moves;

        winner = checkWinner(board);
        if (winner != ' ') {
            displayBoard(board);
            cout << "*** Player " << winner << " wins! ***\n";
            if (winner == 'X') ++xWins; else ++oWins;
            break;
        }

        if (isBoardFull(board)) {
            displayBoard(board);
            cout << "*** It's a draw! ***\n";
            ++draws;
            break;
        }

        current = (current == 'X') ? 'O' : 'X';
    }

    cout << "\nScore  ->  X: " << xWins
         << "   O: " << oWins
         << "   Draws: " << draws << '\n';

    string again = "";
    cout << "\nPlay again? (y/n) : ";
    getline(cin, again);
    return (again == "y" || again == "Y");
}

/* ---------------- Main ---------------- */

int main() {
    cout << "=========================================\n";
    cout << "        WELCOME TO TIC TAC TOE\n";
    cout << "=========================================\n";

    int xWins = 0, oWins = 0, draws = 0;

    do {
        // playOnce returns true if user wants another round
    } while (playOnce(xWins, oWins, draws));

    cout << "\nFinal Score -> X: " << xWins
         << "   O: " << oWins
         << "   Draws: " << draws << '\n';
    cout << "Thanks for playing!\n";
    return 0;
}
