// level - easy
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

// tc : O(n * m)
// sc : O(n + m)

class Solution {
public:
    vector<int> zfunction(string& S) {
        int Slen = S.length();
        vector<int> zArray(Slen, 0);

        for (int i = 1; i < Slen; i++) {
            while ((i + zArray[i]) < Slen && S[i + zArray[i]] == S[zArray[i]]) {
                zArray[i]++;
            }
        }

        return zArray;
    }

    int strStr(string text, string pattern) {
        string S = pattern + "$" + text;
        int lenS = S.length();

        vector<int> zArray = zfunction(S);

        int patternLen = pattern.length();

        vector<int> ans;
        for (int i = patternLen + 1; i < lenS; i++) {
            if (zArray[i] == patternLen)
                return i - (patternLen + 1);
        }

        return -1;
    }
};

// tc : ~O(n)
// sc : O(n + m)

class Solution {
public:
    vector<int> zfunction(string& S) {
        int lenS = S.length();
        vector<int> zArray(lenS, 0);

        int left = 0, right = 0;

        for (int i = 1; i < lenS; i++) {
            if (i > right) {
                while ((i + zArray[i]) < lenS &&
                        S[i + zArray[i]] == S[zArray[i]]) {
                    zArray[i]++;
                }
            } else {
                if ((i + zArray[i - left]) <= right)
                    zArray[i] = zArray[i - left];
                else {
                    zArray[i] = right - i + 1;

                    while ((i + zArray[i]) < lenS &&
                            S[i + zArray[i]] == S[zArray[i]]) {
                        zArray[i]++;
                    }
                }
            }

            left = i, right = i + zArray[i] - 1;
        }

        return zArray;
    }

    int strStr(string text, string pattern) {
        string S = pattern + "$" + text;
        int lenS = S.length();

        vector<int> zArray = zfunction(S);

        int patternLen = pattern.length();

        vector<int> ans;
        for (int i = patternLen + 1; i < lenS; i++) {
            if (zArray[i] == patternLen)
                return i - (patternLen + 1);
        }

        return -1;
    }
};