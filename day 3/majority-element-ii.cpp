// level - medium
// https://leetcode.com/problems/majority-element-ii/description/

// tc : O(n)
// sc : O(n)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int occ = n/3;

        map<int, int> freq;
        for(auto &it : nums) {
            freq[it]++;
        }

        vector<int> ans;
        for(auto &it : freq) {
            if(it.second > occ) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};

// tc : O(n)
// sc : O(1)

// extended boyer's moore's algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int ele1 = -1, ele2 = -1;

        for(auto &it : nums) {
            if(count1 == 0 && it != ele2) {
                count1 = 1;
                ele1 = it;
            }
            else if(count2 == 0 && it != ele1) {
                count2 = 1;
                ele2 = it;
            }
            else if(ele1 == it) {
                count1++;
            }
            else if(ele2 == it) {
                count2++;
            }
            else {
                count1--, count2--;
            }
        }

        int cnt1 = 0, cnt2 = 0;
        for(auto &it : nums) {
            if(ele1 == it) cnt1++;
            else if(ele2 == it) cnt2++;
        }

        vector<int> ans;
        if(cnt1 > (nums.size() / 3)) {
            ans.push_back(ele1);
        } 

        if(cnt2 > (nums.size() / 3)) {
            ans.push_back(ele2);
        }

        return ans;
    }
};