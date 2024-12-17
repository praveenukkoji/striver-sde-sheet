// level - medium
// https://leetcode.com/problems/rotate-image/description/

// tc : O(n*n) + O(n*n)
// sc : O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // tanspose and reverse all row

        // transpose
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++)
                swap(matrix[i][j], matrix[j][i]);
        }

        // reversing row
        for(int i=0;i<n;i++) {
            for(int j=0;j<n/2;j++) {
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
    }
};