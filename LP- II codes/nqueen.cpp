#include <iostream>
#include <vector>
using namespace std;

class NQueen {
    int n;
    vector<string> board;

public:
    NQueen(int size) {
        n = size;
        board = vector<string>(n, string(n, '.'));
    }

    bool isSafe(int row, int col) {
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q')
                return false;

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q')
                return false;

        return true;
    }

    bool solveBacktracking(int row) {
        if (row == n)
            return true;

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col)) {
                board[row][col] = 'Q';

                if (solveBacktracking(row + 1))
                    return true;

                board[row][col] = '.';
            }
        }
        return false;
    }

    bool solveBranchBound(int row, vector<bool>& colCheck, vector<bool>& d1, vector<bool>& d2) {
        if (row == n)
            return true;

        for (int col = 0; col < n; col++) {
            if (!colCheck[col] && !d1[row + col] && !d2[row - col + n - 1]) {
                board[row][col] = 'Q';
                colCheck[col] = d1[row + col] = d2[row - col + n - 1] = true;

                if (solveBranchBound(row + 1, colCheck, d1, d2))
                    return true;

                board[row][col] = '.';
                colCheck[col] = d1[row + col] = d2[row - col + n - 1] = false;
            }
        }
        return false;
    }

    void printBoard() {
        for (int i = 0; i < n; i++)
            cout << board[i] << endl;
    }

    void runBacktracking() {
        board = vector<string>(n, string(n, '.'));
        cout << "\nBacktracking Solution:\n";
        if (solveBacktracking(0))
            printBoard();
        else
            cout << "No Solution\n";
    }

    void runBranchBound() {
        board = vector<string>(n, string(n, '.'));
        vector<bool> colCheck(n, false), d1(2 * n - 1, false), d2(2 * n - 1, false);

        cout << "\nBranch and Bound Solution:\n";
        if (solveBranchBound(0, colCheck, d1, d2))
            printBoard();
        else
            cout << "No Solution\n";
    }
};

int main() {
    int n;
    cout << "Enter value of N: ";
    cin >> n;

    NQueen q(n);

    q.runBacktracking();
    q.runBranchBound();

    return 0;
}