// longest happy prefix which is both proper prefix and proper suffix

// level - medium

// tc : O(len(s))
// sc : O(len(s)) -> lps array

class Solution {
public:
    vector<int> lpsFunc(string& str) {
        int n = str.length();

        vector<int> lps(n, 0);

        int i = 1, j = 0;

        while (i < n) {
            if (str[i] == str[j]) {
                lps[i] = j + 1;
                j++;
            } else {
                while (j > 0 && str[i] != str[j]) {
                    j = lps[j - 1];
                }

                if (str[i] == str[j]) {
                    lps[i] = j + 1;
                    j++;
                }
            }

            i++;
        }

        return lps;
    }
    string lps(string s) {
        vector<int> lps = lpsFunc(s);

        int len = lps.back();
        return s.substr(0, len);
    }
};