// level - easy
// https://leetcode.com/problems/next-greater-element-i/description/

// tc : O(n1 * n2)
// sc : O(1) as nge is required to store next greater element

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        vector<int> nge(n2, -1);

        for (int i = 0; i < n2; i++) {
            int ele = nums2[i];
            for (int j = i + 1; j < n2; j++) {
                if (nums2[j] > ele) {
                    nge[i] = nums2[j];
                    break;
                }
            }
        }

        int n1 = nums1.size();
        vector<int> ans(n1, -1);
        for (int i = 0; i < n1; i++) {
            int ele = nums1[i];

            for (int j = 0; j < n2; j++) {
                if (nums2[j] == ele) {
                    ans[i] = nge[j];
                }
            }
        }

        return ans;
    }
};

// tc : O(n1 + n2)
// sc : O(n) for stack

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge(1e4 + 1, -1);
        stack<int> st;

        int n2 = nums2.size();
        for (int i = n2 - 1; i >= 0; i--) {
            while (!st.empty() && st.top() < nums2[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nge[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        int n1 = nums1.size();
        vector<int> ans(n1);
        for (int i = 0; i < n1; i++) {
            ans[i] = nge[nums1[i]];
        }

        return ans;
    }
};