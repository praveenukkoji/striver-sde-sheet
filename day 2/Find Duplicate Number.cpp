// https://leetcode.com/problems/find-the-duplicate-number/description/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = nums[0];
        int f = nums[nums[0]];

        while (s != f) {
            s = nums[s];
            f = nums[nums[f]];
        }

        f = 0;
        while (s != f) {
            f = nums[f];
            s = nums[s];
        }

        return f;
    }
};