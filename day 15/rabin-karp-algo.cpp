// level - easy
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

// tc : O(n * m)
// sc : O(1)

class Solution {
public:
    int strStr(string haystack, string needle) {
        return search(needle, haystack);
    }
    int search(string pat, string txt) {
        int n = txt.length() - pat.length();
        for (int i = 0; i <= n; i++) {
            int ind = i;
            bool isMatching = true;

            for (int j = 0; j < pat.length(); j++) {
                if (txt[i + j] == pat[j]) {
                    continue;
                } else {
                    isMatching = false;
                    break;
                }
            }

            if (isMatching) {
                return i;
            }
        }

        return -1;
    }
};

// tc : O(n + m)
// sc : O(1)

// rolling hash function

class Solution {
public:
    int strStr(string haystack, string needle) {
        return search(needle, haystack);
    }

    int search(string pat, string txt) {
        int patLen = pat.length();
        int txtLen = txt.length();

        int patHash = 0;
        int txtHash = 0;

        int p = 7;
        int MOD = 101;

        int pRight = 1;
        int pLeft = 1;

        for (int i = 0; i < patLen; i++) {
            patHash += ((pat[i] - 'a' + 1) * pRight) % MOD;
            txtHash += ((txt[i] - 'a' + 1) * pRight) % MOD;

            pRight = (pRight * p) % MOD;
        }

        vector<int> pos;

        for (int i = 0; i <= (txtLen - patLen); i++) {
            if (patHash == txtHash) {
                if (txt.substr(i, patLen) == pat) {
                    return i;
                }
            }

            txtHash =
                (txtHash - ((txt[i] - 'a' + 1) * pLeft) % MOD + MOD) % MOD;
            txtHash =
                (txtHash + ((txt[i + patLen] - 'a' + 1) * pRight) % MOD) % MOD;

            patHash = (patHash * p) % MOD;

            pRight = (pRight * p) % MOD;
            pLeft = (pLeft * p) % MOD;
        }

        return -1;
    }
};