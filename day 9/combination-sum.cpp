// level - medium
// https://leetcode.com/problems/combination-sum/

// Time Complexity: O(2^t * k) where t is the target, k is the average length
// Reason: Assume if you were not allowed to pick a single element multiple times, 
// every element will have a couple of options: pick or not pick which is 2^n different 
// recursion calls, also assuming that the average length of every combination generated is k. 
// (to put length k data structure into another data structure).

// Why not (2^n) but (2^t) (where n is the size of an array)?
// Assume that there is 1 and the target you want to reach is 10 so 10 times you can 
// “pick or not pick” an element.

// Space Complexity: O(k*x), k is the average length and x is the no. of combinations

class Solution {
public:
    void func(int ind, vector<int>& candidates, int target, vector<int>& temp, int sum, vector<vector<int>>& ans) {
        if(ind == candidates.size()) {
            if(sum == target)
                ans.push_back(temp);
            return;
        }

        if((sum + candidates[ind]) <= target) {
            sum += candidates[ind];
            temp.push_back(candidates[ind]);
            func(ind, candidates, target, temp, sum, ans);
            sum -= candidates[ind];
            temp.pop_back();
        }
        
        func(ind + 1, candidates, target, temp, sum, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = (int)candidates.size();
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;

        func(0, candidates, target, temp, sum, ans);

        return ans;
    }
};