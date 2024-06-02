// https://leetcode.com/problems/pascals-triangle/description/

class Solution {
public:
    vector<int> generateRow(int r) {
        long long ans = 1;
        vector<int> row;

        row.push_back(ans);

        for (int col = 1; col < r; col++) {
            ans = ans * (r - col);
            ans = ans / col;
            row.push_back(ans);
        }

        return row;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 1; i <= numRows; i++) {
            ans.push_back(generateRow(i));
        }

        return ans;
    }
};