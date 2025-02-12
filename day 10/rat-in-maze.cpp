// level - medium
// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

// tc : O(4^(n^2))
// sc : O(n^2)

class Solution {
  public:
    // D, L, R, U
    vector<int> dirR = {1, 0, 0, -1};
    vector<int> dirC = {0, -1, 1, 0};
    vector<char> dir = {'D', 'L', 'R', 'U'};
    
    bool isValid(int r, int c, int n) {
        return (r >= 0 && r < n && c >= 0 && c < n);
    }
    
    void generatePaths(int r, int c, int n, vector<vector<int>>& mat, vector<vector<bool>>& visited, string path, vector<string>& paths) {
        if(r == (n-1) && c == (n-1)) {
            paths.push_back(path);
            return;
        }
        
        for(int d=0;d<4;d++) {
            int newR = r + dirR[d];
            int newC = c + dirC[d];
            
            if(isValid(newR, newC, n) && !visited[newR][newC] && mat[newR][newC]) {
                visited[newR][newC] = true;
                generatePaths(newR, newC, n, mat, visited, path + dir[d], paths);
                
                visited[newR][newC] = false;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        int n = (int)mat.size();
        vector<string> paths;
        
        if(mat[0][0] == 0) return paths;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;
        
        generatePaths(0, 0, n, mat, visited, "", paths);
        
        return paths;
    }
};