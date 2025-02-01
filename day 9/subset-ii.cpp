// level - medium
// https://leetcode.com/problems/subsets-ii/description/

// tc : O((2^n) * (k * log(x)))
        // 2^n  for generating every subset and (k * log(x)) to insert every combination of 
        // average length k in a set of size x. After this, we have to convert the set of 
        // combinations back into a list of list /vector of vectors which takes more time.

// sc : O(2^n * k) to store every subset of average length k. 
        // Since we are initially using a set to store the answer another O(2^n *k) is also used.

class Solution {
public:
    void getSubset(int ind, vector<int>& nums, vector<int> temp, set<vector<int>>& ans) {
        if(ind == nums.size()) {
            sort(temp.begin(), temp.end());
            ans.insert(temp);
            return;
        }

        // pick
        temp.push_back(nums[ind]);
        getSubset(ind+1, nums, temp, ans);

        // not pick
        temp.pop_back();
        getSubset(ind+1, nums, temp, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;

        getSubset(0, nums, temp, ans);

        vector<vector<int>> ans1(ans.begin(), ans.end());
        return ans1;
    }
};

// tc : O(n * log(n)) + O(2^n * k) 
// sc : O(2^n * k) + O(n)

class Solution {
public:
    void findSubsets(int ind, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        ans.push_back(temp);

        for(int i=ind; i<nums.size(); i++) {
            if(i != ind && nums[i] == nums[i-1]) continue;

            temp.push_back(nums[i]);
            findSubsets(i+1, nums, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(nums.begin(), nums.end());
        findSubsets(0, nums, temp, ans);

        return ans;
    }
};
