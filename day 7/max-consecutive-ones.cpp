// level - easy
// https://leetcode.com/problems/max-consecutive-ones/description/

// tc : O(n)
// sc : O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int mx = INT_MIN;
        int curr = (nums[0] == 1 ? 1 : 0);

        for(int i=1;i<n;i++) {
            if(nums[i] == 1) {
                curr++;
            }
            else {
                mx = max(mx, curr);
                curr = 0;
            }
        }

        mx = max(mx, curr);

        return mx;
    }
};