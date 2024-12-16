// level - easy
// https://leetcode.com/problems/pascals-triangle/description/

// tc : O(n*n)
// sc : O(1) because array is used to store ans not for computation

// print pascal triangle for first n number of rows
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i=1;i<=numRows;i++) {
            vector<int> temp;

            int ele = 1;
            temp.push_back(ele);

            for(int j=1;j<i;j++) {
                ele = ele*(i-j);
                ele = ele/j;
                temp.push_back(ele);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};

// tc : O(n)
// sc : O(1) because array is used to store ans not for computation

// print entire row for given rowNum
class Solution {
public:
    vector<int> generate(int numRows) {
        vector<int> ans;

        int ele = 1;
        ans.push_back(ele);

        for(int j=1;j<numRows;j++) {
            ele = ele*(numRows-j);
            ele = ele/j;
            ans.push_back(ele);
        }

        return ans;
    }
};

// tc : O(n)
// sc : O(1) because array is used to store ans not for computation

// print value at (n,r)
class Solution {
public:
    int generate() {
        int n = 5, r = 3;
        n = n-1;
        r = r-1;
        long long ans = 1;

        for(int i=0;i<r;i++) {
            ans = ans * (n - i);
            ans = ans / (i + 1);
        }

        return ans;
    }
};