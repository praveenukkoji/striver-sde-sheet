// level - medium
// 

// tc : O(n^3)
// sc : O(1)

class Solution {
public:
    bool solve(const string& s, int i, int j) {
        if((j - i + 1) <= 1)
            return true;
        
        if(s[i] == s[j]) {
            return solve(s, i + 1, j - 1);
        }

        return false;
    }

    string longestPalindrome(string s) {
        int n = s.length();

        if(n <= 1)
            return s;

        int start = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(s, i, j)) {
                    if (maxLen < (j - i + 1)) {
                        start = i;
                        maxLen = (j - i + 1);
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

// tc : O(n^2)
// sc : O(n^2)

// top-down (Memoization) approach

class Solution {
public:
    bool solve(const string& s, int i, int j, int dp[1001][1001]) {
        if((j - i + 1) <= 1)
            return true;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == s[j]) {
            return dp[i][j] = solve(s, i + 1, j - 1, dp);
        }

        return dp[i][j] = false;
    }

    string longestPalindrome(string s) {
        int n = s.length();

        if(n <= 1)
            return s;

        int start = 0;
        int maxLen = 0;

        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(s, i, j, dp)) {
                    if (maxLen < (j - i + 1)) {
                        start = i;
                        maxLen = (j - i + 1);
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

// tc : O(n^2)
// sc : O(n^2)

// bottom-up (Tablulation) approach

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        int maxLen = 1;
        int start = 0;
        int end = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            for (int j = 0; j < n; j++) {
                if (s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    if ((i - j + 1) > maxLen) {
                        maxLen = i - j + 1;
                        start = j;
                        end = i;
                    }
                }
            }
        }

        return s.substr(start, end - start + 1);
    }
};

// tc : O(n^2)
// sc : O(1)

class Solution {
public:
    string getEvenOddStr(const string& str, int left, int right) {
        int n = str.length();
        while (left >= 0 && right < n && str[left] == str[right]) {
            left--;
            right++;
        }

        return str.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        int n = s.length();

        if(n <= 1)
            return s;

        string maxStr = s.substr(0, 1);

        for (int i = 0; i < n - 1; i++) {
            string odd = getEvenOddStr(s, i, i);
            string even = getEvenOddStr(s, i, i + 1);

            if (odd.length() > maxStr.length()) {
                maxStr = odd;
            }

            if (even.length() > maxStr.length()) {
                maxStr = even;
            }
        }

        return maxStr;
    }
};