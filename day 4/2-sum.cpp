// level - easy
// https://leetcode.com/problems/two-sum/description/

// tc : O(n^2)
// sc : O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        for(int i=0;i<n;i++) {
            int temp = target - nums[i];

            for(int j=0;j<n;j++) {
                if(i != j && nums[j] == temp) {
                    return {i, j};
                }
            }
        }

        return {-1, -1};
    }
};

// tc : O(n)
// sc : O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for(int i=0;i<n;i++) {
            int temp = nums[i];

            if(mp.find(target - temp) != mp.end()) {
                return {i, mp[target-temp]};
            }

            mp[temp] = i;
        }

        return {-1, -1};
    }
};