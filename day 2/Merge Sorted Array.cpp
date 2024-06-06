// https://leetcode.com/problems/merge-sorted-array/description/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {
            return;
        }

        if (m == 0) {
            for (int i = 0; i < n; i++) {
                nums1[i] = nums2[i];
            }
            return;
        }
        
        int last = m + n - 1;

        m = m - 1;
        n = n - 1;

        while (m >= 0 && n >= 0) {
            if (nums2[n] > nums1[m]) {
                nums1[last] = nums2[n];
                n--;
            } else {
                nums1[last] = nums1[m];
                m--;
            }
            last--;
        }

        while(n > -1) {
            nums1[last] = nums2[n];
            n--;
            last--;
        }
    }
};