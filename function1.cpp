#include <iostream>
#include <vector>

#include "function1.h"

using namespace std;

bool isSafe(vector<int>& board, int row, int col) {
    // Check if the queen can be placed in this position without attacking other queens

    // Check for queens in the same column
    for (int i = 0; i < row; i++) {
        if (board[i] == col)
            return false;
    }

    // Check for queens in the upper diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i] == j)
            return false;
    }

    // Check for queens in the lower diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++) {
        if (board[i] == j)
            return false;
    }

    return true;
}

void solveNQueensUtil(vector<int>& board, int row, int n, int& count) {
    // Base case: all queens are placed
    if (row == n) {
        // Print the board
        cout << "Solution " << count << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i] == j)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
        cout << endl;

        count++;
        return;
    }

    // Try placing the queen in each column of the current row
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            // Place the queen in this position
            board[row] = col;

            // Recur for the next row
            solveNQueensUtil(board, row + 1, n, count);

            // Backtrack and try the next column
            board[row] = -1;
        }
    }
}

void solveNQueens(int n) {
    vector<int> board(n, -1);  // Board representation: board[row] = column

    int count = 1;
    solveNQueensUtil(board, 0, n, count);

    if (count == 1)
        cout << "No solutions found for N = " << n << "." << endl;
    else
        cout << "Total solutions for N = " << n << ": " << count - 1 << endl;
}
