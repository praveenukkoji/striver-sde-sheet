// level - medium
// https://leetcode.com/problems/rotting-oranges/description/

// tc : O(n^2) * 4 -> We will be making each fresh orange rotten in the grid and for each rotten orange will check in 4 directions
// sc : O(n^2)->queue + O(n^2)->visited

class Solution {
public:
    bool isValid(int newRow, int newCol, int m, int n) {
        return (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int freshOranges = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        int time = 0;
        vector<int> dir = {-1, 0, 1, 0, -1};

        int rottenOranges = 0;

        while (!q.empty()) {
            auto orange = q.front();
            int row = orange.first.first;
            int col = orange.first.second;
            int currTime = orange.second;
            q.pop();

            time = max(time, currTime);

            for (int d = 0; d < 4; d++) {
                int newRow = row + dir[d];
                int newCol = col + dir[d + 1];

                if (isValid(newRow, newCol, m, n) && !visited[newRow][newCol] &&
                    grid[newRow][newCol] == 1) {
                    visited[newRow][newCol] = true;
                    q.push({{newRow, newCol}, currTime + 1});
                    rottenOranges++;
                }
            }
        }

        if (freshOranges == rottenOranges) {
            return time;
        }

        return -1;
    }
};