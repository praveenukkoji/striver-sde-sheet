// https://leetcode.com/problems/next-permutation/description/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int br_pt = -1;
        int n = nums.size();

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                br_pt = i;
                break;
            }
        }

        if (br_pt == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n - 1; i > br_pt; i--) {
            if (nums[i] > nums[br_pt]) {
                swap(nums[i], nums[br_pt]);
                break;
            }
        }

        reverse(nums.begin() + br_pt + 1, nums.end());
        return;
    }
};