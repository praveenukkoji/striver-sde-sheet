// level - easy
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

// tc : O(n*logn) n->count_of_unique_element
// sc : O(n) n->count_of_unique_element

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        map<int, int> mp;
        for(int i=0;i<n;i++) {
            mp[nums[i]] = 1;
        }

        int i = 0;
        for(auto& [f, s] : mp) {
            nums[i++] = f;
        }

        return mp.size();
    }
};

// tc : O(n)
// sc : O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int sortedInd = 0;
        for(int i=1;i<n;i++) {
            if(nums[i] != nums[sortedInd]) {
                nums[++sortedInd] = nums[i];
            }
        }

        return (sortedInd+1);
    }
};