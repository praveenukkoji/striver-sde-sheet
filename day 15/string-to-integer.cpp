// level - easy
// https://leetcode.com/problems/string-to-integer-atoi/description/

// tc : O(n)
// sc : O(1)

class Solution {
public:
    bool isDigit(char ch) { return (ch >= '0' && ch <= '9'); }
    int myAtoi(string s) {
        int n = s.length();

        int i = 0;
        while (i < n && s[i] == ' ') {
            i++;
        }
        // cout << "1: " << i << endl;

        bool isNegative = false;
        if (s[i] == '-') {
            isNegative = true;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        // cout << "2: " << i << endl;

        if (!isDigit(s[i])) {
            return 0;
        }
        // cout << "3: " << i << endl;

        while (i < n && s[i] == '0') {
            i++;
        }
        // cout << "4: " << i << endl;

        long long num = 0;
        while (i < n && isDigit(s[i])) {
            char ch = s[i];
            num = (num * 10) + (int(ch) - 48);
            if (isNegative && num > 2147483647) {
                num = 2147483648;
                break;
            } else if (num >= 2147483647) {
                num = 2147483647;
                break;
            }
            i++;
        }

        if (isNegative)
            num = (-1) * num;

        return (int)num;
    }
};