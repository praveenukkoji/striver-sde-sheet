// level - medium
// https://leetcode.com/problems/top-k-frequent-elements/description/

// tc : O(n) freq + O(n * logk)
// sc : O(n) + O(2 * k)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int ele: nums) {
            freq[ele]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto& it: freq) {
            pq.push({it.second, it.first});

            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};