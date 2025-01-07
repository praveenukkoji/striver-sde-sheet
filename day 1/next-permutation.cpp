// level - medium
// https://leetcode.com/problems/next-permutation/description/

// pre-requisite, print all possible permutation
// https://leetcode.com/problems/permutations/description/

// for a given number n it has n! permutation
// tc : O(n!*n)
// sc : O(2*nums.size())

// print all possible permutation
// approach 1
class Solution {
public:
    void generatePermutation(vector<int> &permutation, vector<vector<int>> &ans, vector<int> &usedElement, vector<int> nums) {
        if(permutation.size() == nums.size()) {
            ans.push_back(permutation);
            return;
        }

        for(int i=0;i<nums.size();i++) {
            if(!usedElement[i]) {
                usedElement[i] = 1;
                permutation.push_back(nums[i]);
                generatePermutation(permutation, ans, usedElement, nums);
                permutation.pop_back();
                usedElement[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> permutation;

        vector<int> usedElement(nums.size(), 0);
        generatePermutation(permutation, ans, usedElement, nums);

        return ans;
    }
};

// tc : O(n!*n) 
// sc : O(1)

//approach 2
class Solution {
public:
    void generatePermutation(int ind, vector<int> &nums, vector<vector<int>> &ans) {
        if(ind == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        for(int i=ind;i<nums.size();i++) {
            swap(nums[i], nums[ind]);
            generatePermutation(ind+1, nums, ans);
            swap(nums[i], nums[ind]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        generatePermutation(0, nums, ans);

        return ans;
    }
};

// next-permutation

// tc : O(3*n)
// sc : O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakPoint = -1;

        // find the break point
        for(int i=n-2;i>=0;i--) {
            if(nums[i] < nums[i+1]) {
                breakPoint = i;
                break;
            }
        }

        // if break point is -1 then ans is first permutation
        if(breakPoint == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // find smallest number which is greater than nums[breakPoint]
        for(int i=n-1;i>breakPoint;i--) {
            if(nums[i] > nums[breakPoint]) {
                swap(nums[i], nums[breakPoint]);
                break;
            }
        }

        // now the right part of array after breakpoint just sort it in increasing order or it is already in decreasing order just reverse it
        reverse(nums.begin() + breakPoint + 1, nums.end());
    }
};