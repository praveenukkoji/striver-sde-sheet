// https://leetcode.com/problems/maximum-subarray/description/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        long long max_sum_so_far = INT_MIN;
        long long cur_sum = 0;

        for(int i=0;i<nums.size();i++) {
            cur_sum += nums[i];

            if(cur_sum > max_sum_so_far) 
                max_sum_so_far = cur_sum;

            if(cur_sum < 0) 
                cur_sum = 0;
        }

        return max_sum_so_far;
    }
};