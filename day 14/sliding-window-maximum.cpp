// level - hard
// https://leetcode.com/problems/sliding-window-maximum/

// tc : O(n ^ 2)
// sc : O(2 * n)

class Solution {
public:
    void getMax(const vector<int>& window, int start, int end,
                vector<int>& ans) {
        int mx = window[start];

        for (int i = start; i <= end; i++) {
            mx = max(mx, window[i]);
        }

        ans.push_back(mx);
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> window;

        for (int i = 0; i < k; i++) {
            window.push_back(nums[i]);
        }

        vector<int> ans;
        getMax(window, 0, k - 1, ans);

        for (int i = k; i < n; i++) {
            window.push_back(nums[i]);
            getMax(window, i - k + 1, i, ans);
        }

        return ans;
    }
};

// tc : O(n)
// sc : O(n - k) -> ans  + O(n) -> dq

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ans;

        deque<int> dq;
        for (int i = 0; i < n; i++) {
            while (!dq.empty() && dq.front() <= (i - k)) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= (k - 1)) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};