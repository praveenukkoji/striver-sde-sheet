// level - medium
// https://leetcode.com/problems/unique-paths/description/

// tc : The time complexity of this recursive solution is exponential.
// sc : As we are using stack space for recursion so the space complexity will also be exponential.

class Solution {
public:
    int countPaths(int i, int j, int n, int m) {
        if((i == (n-1)) && (j == (m-1))) return 1;

        if(i >= n || j >= m) return 0;

        return countPaths(i+1, j, n, m) + countPaths(i, j+1, n, m);
    }
    int uniquePaths(int m, int n) {
        return countPaths(0,0,m,n);
    }
};

// tc : O(n*m)
// sc : O(n*m)

class Solution {
public:
    int uniquePaths(int m, int n) {
        swap(m,n);

        if(n == 1) return 1;
        if(m == 1) return 1;

        vector<vector<int>> grid(n, vector<int> (m));
        grid[0][0] = 0;

        for(int j=1;j<n;j++) {
            grid[j][0] = 1;
        }

        for(int i=1;i<m;i++) {
            grid[0][i] = 1;
        }

        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }

        return grid[n-1][m-1];
    }
};

