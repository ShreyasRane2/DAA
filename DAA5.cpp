#include <iostream>
#include <vector>

using namespace std;

// Function to check if it's safe to place a queen at (row, col)
bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
    // Check this column on the upper side
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check the upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check the upper diagonal on the right side
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Function to print the board
void printBoard(const vector<vector<int>>& board) {
    cout << "Current board configuration:\n";
    for (const auto& row : board) {
        for (int cell : row) {
            if (cell == 1) {
                cout << "[Q] "; // Queen representation
            } else {
                cout << "[ ] "; // Empty space representation
            }
        }
        cout << endl; // Move to the next line after each row
    }
    cout << endl; // Add an extra line for better separation
}

// Recursive utility function to solve the N-Queens problem
void solveNQueens(vector<vector<int>>& board, int row, int n) {
    // If all queens are placed, print the board
    if (row == n) {
        printBoard(board); // Print the valid board configuration
        return;
    }

    // Try placing queens in all columns of the current row
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            // Place the queen
            board[row][col] = 1;

            // Recursively place the remaining queens
            solveNQueens(board, row + 1, n);

            // Backtrack: remove the queen
            board[row][col] = 0; // Reset the position
        }
    }
}

// Function to initiate the N-Queens problem
void nQueens(int n, int firstRow, int firstCol) {
    vector<vector<int>> board(n, vector<int>(n, 0)); // Create an n x n board initialized to 0

    // Place the first queen
    board[firstRow][firstCol] = 1;

    // Start placing the remaining queens from the next row
    solveNQueens(board, firstRow + 1, n);
}

int main() {
    int n, firstRow, firstCol;

    cout << "Enter the size of the board (N): ";
    cin >> n;

    // Validate board size input
    if (n <= 0) {
        cout << "Invalid board size. Please enter a positive integer." << endl;
        return 1;
    }

    cout << "Enter the row and column to place the first Queen (0-indexed): ";
    cin >> firstRow >> firstCol;

    // Validate the position
    if (firstRow < 0 || firstRow >= n || firstCol < 0 || firstCol >= n) {
        cout << "Invalid position for the first queen. Please enter values between 0 and " << n - 1 << "." << endl;
        return 1;
    }

    cout << "All possible solutions with the first queen placed at (" 
         << firstRow << ", " << firstCol << "):" << endl;
    
    nQueens(n, firstRow, firstCol);

    return 0;
}
