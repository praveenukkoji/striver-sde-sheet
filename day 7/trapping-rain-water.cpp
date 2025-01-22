// level - medium
// https://leetcode.com/problems/trapping-rain-water/description/

// tc : O(n)
// sc : O(n) + O(n)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> pref(n, 0);
        vector<int> suff(n, 0);

        pref[0] = height[0];
        suff[n-1] = height[n - 1];

        for(int i=1;i<n;i++) {
            pref[i] = max(pref[i-1], height[i]);
            suff[n - i - 1] = max(suff[n - i], height[n - i - 1]);
        }

        int water = 0;
        for(int i=0;i<n;i++) {
            water += min(pref[i], suff[i]) - height[i];
        }

        return water;
    }
};

// tc : O(n)
// sc : O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        if(n <= 2) return 0;

        int mxLeft = height[0];
        int mxRight = height[n-1];

        int left = 1;
        int right = n-1;

        int water = 0;

        while(left <= right) {
            if(mxLeft <= mxRight) {
                if(height[left] >= mxLeft) {
                    mxLeft = height[left];
                }
                else {
                    water += mxLeft - height[left];
                }

                left++;
            }
            else {
                if(height[right] >= mxRight) {
                    mxRight = height[right];
                }
                else {
                    water += mxRight - height[right];
                }

                right--;
            }
        }

        return water;
    }
};