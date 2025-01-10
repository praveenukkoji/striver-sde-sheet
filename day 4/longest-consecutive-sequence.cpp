// level - medium
// https://leetcode.com/problems/longest-consecutive-sequence/description/

// tc : O(n^2)
// sc : O(1)

class Solution {
public:
    bool linearSearch(vector<int>& a, int temp) {
        for(int i=0;i<a.size();i++) {
            if(a[i] == temp) return true;
        }

        return false;
    }

    int longestConsecutive(vector<int>& nums) {
        int n= nums.size();

        int maxLen = 0;

        for(int i=0;i<n;i++) {
            int temp = nums[i];
            int cnt = 1;

            while(linearSearch(nums, temp+1) == true) {
                temp += 1;
                cnt++;
            }

            maxLen = max(maxLen, cnt);
        }

        return maxLen;
    }
};

// tc : O(n*logn)
// sc : O(1)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n= nums.size();

        sort(nums.begin(), nums.end());

        int cnt = 0;
        int lastSmaller = INT_MIN;
        int maxLen = 0;

        for(int i=0;i<n;i++) {
            if(nums[i] == lastSmaller+1) {
                // cout<<"1: "<<nums[i]<<endl;
                lastSmaller = nums[i];
                cnt += 1;
            }
            else if(nums[i] == lastSmaller) continue;
            else {
                // cout<<"2: "<<nums[i]<<endl;
                lastSmaller = nums[i];
                cnt = 1;
            }

            maxLen = max(maxLen, cnt);
        }

        return maxLen;
    }
};

// tc : O(n)
// sc : O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st;
        for(auto &it: nums) {
            st.insert(it);
        }

        int maxLen = 0;

        for(auto &it : st) {
            int temp = it;

            if(st.find(temp-1) == st.end()) {
                int cnt = 1;
                while(st.find(temp+1) != st.end()) {
                    temp += 1;
                    cnt += 1;
                }
                maxLen = max(maxLen, cnt);
            }
        }

        return maxLen;
    }
};