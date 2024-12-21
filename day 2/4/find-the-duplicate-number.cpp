// level - medium
// https://leetcode.com/problems/find-the-duplicate-number/description/

// tc : O(n*logn)
// sc : O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i=1;nums.size();i++) {
            int prev = i - 1;

            if(nums[prev] == nums[i]) {
                return nums[i];
            }
        }

        return -1;
    }
};

// tc : O(n)
// sc : O(n)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> frequency(nums.size()-1);

        for(auto &it : nums) {
            frequency[it-1] += 1;
        }

        for(int i=0;i<frequency.size();i++) {
            if(frequency[i] > 1) {
                return i+1;
            }
        }

        return -1;
    }
};

// tc : O(n)
// sc : O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        fast = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};