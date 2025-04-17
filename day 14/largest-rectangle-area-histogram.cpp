// level - hard
// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

// tc : O(n) + O(n) + O(n)  = O(3n)
// sc : O(n + n) + O(n + n) = O(4n)

class Solution {
public:
    void findPse(const vector<int>& heights, vector<int>& pse) {
        int n = heights.size();

        stack<pair<int, int>> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first >= heights[i]) {
                st.pop();
            }

            pse[i] = (st.empty()) ? -1 : st.top().second;

            st.push({heights[i], i});
        }
    }
    void findNse(const vector<int>& heights, vector<int>& nse) {
        int n = heights.size();

        stack<pair<int, int>> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first >= heights[i]) {
                st.pop();
            }

            nse[i] = (st.empty()) ? n : st.top().second;

            st.push({heights[i], i});
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> pse(n);
        vector<int> nse(n);

        findPse(heights, pse);
        findNse(heights, nse);

        long long area = 0;
        for (int i = 0; i < n; i++) {
            area = max(area, 1LL * heights[i] * (nse[i] - pse[i] - 1));
        }

        return (int)area;
    }
};

// tc : O(n) + O(n) = O(2n)
// sc : O(n)        = O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<pair<int, int>> st;
        long long area = 0;

        for(int i=0;i<n;i++) {
            while(!st.empty() && st.top().first > heights[i]) {
                auto ele = st.top();
                st.pop();

                int nse = i;
                int pse = (st.empty()) ? -1 : st.top().second;

                area = max(area, 1LL * ele.first * (nse - pse - 1));
            }

            st.push({heights[i], i});
        }

        while(!st.empty()) {
            auto ele = st.top();
            st.pop();

            int nse = n;
            int pse = (st.empty()) ? -1 : st.top().second;

            area = max(area, 1LL * ele.first * (nse - pse - 1));
        }

        return area;
    }
};