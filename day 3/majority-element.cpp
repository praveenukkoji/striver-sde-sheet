// level - easy
// https://leetcode.com/problems/majority-element/description/

// tc : O(n)
// sc : O(n)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(auto &it : nums) {
            freq[it]++;
        }

        int halfSize = nums.size()/2;

        for(auto &it : freq) {
            if(it.second > halfSize) {
                return it.first;
            }
        }

        return 0;
    }
};

// tc : O(n)
// sc : O(1)

// moore's voting algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int ele = nums[0];

        for(auto &it : nums) {
            if(count == 0) {
                count = 1;
                ele = it;
            }
            else if(it == ele) {
                count++;
            }
            else {
                count--;
            }
        }

        int count1 = 0;
        for(auto &it : nums) {
            if(it == ele) count1++;
        }

        if(count1 > (nums.size() / 2)) {
            return ele;
        }

        return -1;
    }
};