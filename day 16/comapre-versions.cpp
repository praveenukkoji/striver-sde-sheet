// level - medium
// https://leetcode.com/problems/compare-version-numbers/description/

// tc : O(max(n1, n2))
// sc : O(1)

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size();
        int n2 = version2.size();

        int i = 0, j = 0;
        while (i < n1 || j < n2) {
            long long rev1 = 0;
            while (i < n1 && version1[i] != '.') {
                rev1 = rev1 * 10 + (version1[i] - '0');
                i++;
            }

            long long rev2 = 0;
            while (j < n2 && version2[j] != '.') {
                rev2 = rev2 * 10 + (version2[j] - '0');
                j++;
            }

            if (rev1 < rev2) {
                return -1;
            } else if (rev1 > rev2) {
                return 1;
            }

            // skipping '.'
            i++;
            j++;
        }

        return 0;
    }
};