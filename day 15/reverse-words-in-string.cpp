// level - medium
// https://leetcode.com/problems/reverse-words-in-a-string/description/

// tc : O(n)
// sc : O(n) ans

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();

        string ans = "";

        int i = 0;
        while (i < n) {
            while (i < n && s[i] == ' ')
                i++;

            string temp = "";
            while (i < n && s[i] != ' ') {
                temp.push_back(s[i]);
                i++;
            }

            if(temp.empty())
                break;

            if(ans != "" ) 
                ans = temp + " " + ans;
            else
                ans = temp;
        }

        return ans;
    }
};

// tc : O(n)
// sc : O(n)

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int n = s.length();
        int i = 0;

        while (i < n) {
            while (i < n && s[i] == ' ') i++;

            string temp = "";
            while (i < n && s[i] != ' ') {
                temp.push_back(s[i]);
                i++;
            }

            if (!temp.empty())
                words.push_back(temp);
        }

        reverse(words.begin(), words.end());
        string ans = "";
        for (int i = 0; i < words.size(); i++) {
            ans += words[i];
            if (i != words.size() - 1)
                ans += " ";
        }

        return ans;
    }
};