// level - medium
// https://leetcode.com/problems/permutations/description/

// tc : O(n! * n)
// sc : O(n!)

class Solution {
public:
    void generatePermutation(int ind, vector<int>& nums, vector<int>& temp, vector<bool>& freq, vector<vector<int>>& ans) {
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++) {
            if(!freq[i]) {
                temp.push_back(nums[i]);
                freq[i] = true;

                generatePermutation(i+1, nums, temp, freq, ans);

                temp.pop_back();
                freq[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = (int)nums.size();

        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> freq(n, false);

        generatePermutation(0, nums, temp, freq, ans);
        return ans;
    }
};

// tc : O(n!)
// sc : O(1)

class Solution {
public:
    void generate(int ind, vector<int>& nums, vector<vector<int>>& ans) {
        if(ind == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        for(int i=ind;i<nums.size();i++) {
            swap(nums[i], nums[ind]);
            generate(ind+1, nums, ans);
            swap(nums[i], nums[ind]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        generate(0, nums, ans);
        return ans;
    }
};