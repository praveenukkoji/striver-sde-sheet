// level - medium
// https://leetcode.com/problems/maximum-subarray/description/

// tc : O(n^3)
// sc : O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int mSum = INT_MIN;

        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                int currSum = 0;

                for(int k=i;k<=j;k++) {
                    currSum += nums[k];
                } 

                mSum = max(mSum, currSum);
            }
        }

        return mSum;
    }
};

// tc : O(n^2)
// sc : O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int mSum = INT_MIN;

        for(int i=0;i<n;i++) {
            int currSum = 0;
            for(int j=i;j<n;j++) {
                currSum += nums[j];
                mSum = max(mSum, currSum);
            }
        }

        return mSum;
    }
};

// tc : O(n)
// sc : O(1)

// Kaden's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int mSum = INT_MIN;
        int cSum = 0;

        for(int i=0;i<n;i++) {
            cSum += nums[i];

            // update latest max sum
            if(mSum < cSum) mSum = cSum;

            // no point in carrying negative sum so reset to zero
            if(cSum < 0) cSum = 0;
        }

        // considering empty array
        if (maxi < 0) maxi = 0;

        return mSum;
    }
};

// follow up question, asked to print the subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int mSum = INT_MIN;
        int cSum = 0;

        int start = -1;
        int arrStart = -1;
        int arrEnd = -1;

        for(int i=0;i<n;i++) {

            // array always start wher csum = 0
            if(cSum == 0) start = i;

            cSum += nums[i];

            // update latest max sum
            if(mSum < cSum) {
                mSum = cSum;

                arrStart = start, arrEnd = i;
            }

            // no point in carrying negative sum so reset to zero
            if(cSum < 0) cSum = 0;
        }

        // considering empty array
        if (maxi < 0) maxi = 0;

        // print array from arrStart to arrEnd

        return mSum;
    }
};
