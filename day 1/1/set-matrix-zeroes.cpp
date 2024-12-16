// level - medium
// https://leetcode.com/problems/set-matrix-zeroes/description/

// tc : O(2*n*m)
// sc: O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1;

        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int r=0;r<rows;r++) {
            for(int c=0;c<cols;c++) {
                if(matrix[r][c] == 0) {

                    // mark r-th row 0
                    matrix[r][0] = 0;

                    // mark c-th col 0
                    if(c != 0) {
                        matrix[0][c] = 0;
                    }
                    else {
                        col0 = 0;
                    }
                }
            }
        }

        // marking elements to marked as 0 in final array
        for(int r=1;r<rows;r++) {
            for(int c=1;c<cols;c++) {
                if(matrix[r][c] != 0) {
                    if(matrix[0][c] == 0 || matrix[r][0] == 0) {
                        matrix[r][c] = 0;
                    }
                }
            }
        }

        // solving for first row
        if(matrix[0][0] == 0) {
            for(int c=0;c<cols;c++) {
                matrix[0][c] = 0;
            }
        }

        // solving for first col
        if(col0 == 0) {
            for(int r=0;r<rows;r++) {
                matrix[r][0] = 0;
            }
        }
    }
};

// time complexity : O(n*m) + O(n+m) + O(n*m)
// space complexity : O(size(posZeroList))

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<pair<int, int>> posZeroList;

        // creating list of (r,c) where we have to set its entire row and column to 0
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(matrix[i][j] == 0) {
                    posZeroList.push_back(make_pair(i,j));
                }
            }
        }

        // marking position (r,c) to be replaced with 0
        for(auto posZero : posZeroList) {
            int row = posZero.first;
            int col = posZero.second;

            // up direction
            for(int r=row;r>=0;r--) {
                if(matrix[r][col] != 0) {
                    matrix[r][col] = -1;
                }
            }

            // right direction
            for(int c=col;c<cols;c++) {
                if(matrix[row][c] != 0) {
                    matrix[row][c] = -1;
                }
            }

            // left direction
            for(int c=col;c>=0;c--) {
                if(matrix[row][c] != 0) {
                    matrix[row][c] = -1;
                }
            }

            // down direction
            for(int r=row;r<rows;r++) {
                if(matrix[r][col] != 0) {
                    matrix[r][col] = -1;
                }
            }
        }

        // replacing with zero
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(matrix[i][j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};