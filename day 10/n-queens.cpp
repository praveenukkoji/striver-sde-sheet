// level - hard
// https://leetcode.com/problems/n-queens/description/

// Time and Space Complexity of N-Queens

// Understanding the O(N!) Complexity

// In backtracking, we try to place queens one row at a time. At each row, we explore all possible column placements while ensuring no two queens attack each other.

// First queen: We have N choices (any column in row 0).

// Second queen: Can be placed in at most (N-1) valid positions (since one column is already occupied).

// Third queen: Can be placed in at most (N-2) valid positions.

// ... This pattern continues.

// Nth queen: Has at most 1 valid position.

// Thus, the number of possible placements is approximately:

// N * (N-1) * (N-2) * ... * 1 = N!

// This gives a worst-case time complexity of O(N!).

// tc : O(n! * n)
// sc : O(n^2)

class Solution {
public:
    bool isValid(int row, int col, vector<string>& board, int n) {
        int dupRow = row;
        int dupCol = col;
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = dupRow;
        col = dupCol;
        while(col >= 0) {
            if(board[row][col] == 'Q') return false;
            col--;
        }

        row = dupRow;
        col = dupCol;
        while(row < n && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    }
    
    void fillBoard(int col, int n, vector<string>& board, vector<vector<string>>& ans) {
        if(col == n) {
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++) {
            if(isValid(row, col, board, n)) {
                board[row][col] = 'Q';
                fillBoard(col+1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);

        string str(n, '.');
        for(int i=0;i<n;i++) {
            board[i] = str;
        }

        fillBoard(0, n, board, ans);
        return ans;
    }
};

// tc : O(n! * n)
// sc : O(n)

class Solution {
public:    
    void fillBoard(int col, int n, vector<string>& board, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, vector<vector<string>>& ans) {
        if(col == n) {
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++) {
            if(leftRow[row] == 0 && upperDiagonal[row + col] == 0 && lowerDiagonal[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperDiagonal[row + col] = 1;
                lowerDiagonal[n - 1 + col - row] = 1;
                fillBoard(col+1, n, board, leftRow, upperDiagonal, lowerDiagonal, ans);

                leftRow[row] = 0;
                upperDiagonal[row + col] = 0;
                lowerDiagonal[n - 1 + col - row] = 0;
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);

        string str(n, '.');
        for(int i=0;i<n;i++) {
            board[i] = str;
        }

        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        fillBoard(0, n, board, leftRow, upperDiagonal, lowerDiagonal, ans);
        return ans;
    }
};