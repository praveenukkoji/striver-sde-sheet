// level - medium
// 

// Time Complexity:O(2^n*k)
// Reason: Assume if all the elements in the array are unique then the no. of subsequence you will 
// get will be O(2^n). we also add the temp to our ans when we reach the base case that 
// will take “k” average space for the temp.

// Space Complexity:O(k*x)
// Reason: if we have x combinations then space will be x*k where k is the average length of the 
// combination.

class Solution {
public:
    void func(int ind, vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& ans) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        for(int i=ind;i<candidates.size();i++) {
            if(i > ind && candidates[i-1] == candidates[i]) continue;

            if(candidates[i] > target) break;

            temp.push_back(candidates[i]);
            func(i + 1, candidates, target-candidates[i], temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = (int)candidates.size();

        vector<vector<int>> ans;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());
        func(0, candidates, target, temp, ans);

        return ans;
    }
};