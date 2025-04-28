// minimum character to be added in front to make palindrome
// level - medium

// tc : O(N)
// sc : O(N)

// N -> len of str

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
    string shortestPalindrome(string s) {
        string revStr = s;
        reverse(revStr.begin(), revStr.end());

        string str = s + "$" + revStr;
        vector<int> lps = lpsFunc(str);

        int match_len = lps.back();
        int unmatch_len = s.length() - match_len;

        return revStr.substr(0, unmatch_len) + s;
    }
};