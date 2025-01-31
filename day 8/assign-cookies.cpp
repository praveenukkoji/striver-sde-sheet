// level - medium
// https://leetcode.com/problems/assign-cookies/description/

// tc : O(n * log(n))
// sc : O(1)

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int gSize = (int)g.size();
        int sSize = (int)s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int l = 0, r = 0;

        while(l < sSize && r < gSize) {
            if(s[l] >= g[r]) {
                r++;
            }

            l++;
        }

        return r;
    }
};