// level - 
// 

// tc : O(N^3)
// sc : O(N)

// N -> len of S (S = pattern + "$" + text);

class Solution {
public:
    vector<int> lpsFunc(string& str) {
        int n = str.length();

        vector<int> lps(n, 0);

        for (int i = 1; i < n; i++) {
            for (int len = 1; len < i; len++) {
                if (str.substr(0, len) == str.substr(i - len + 1, len))
                    lps[i] = len;
            }
        }

        return lps;
    }

    vector<int> search(string pat, string txt) {
        string str = pat + "$" + txt;

        vector<int> lps = lpsFunc(str);

        vector<int> pos;
        int patlen = pat.length();
        
        for (int i = patlen + 1; i < lps.size(); i++) {
            if (lps[i] == patlen) {
                pos.push_back(i - (patlen + 1) - patlen + 1);
            }
        }

        return pos;
    }
};

// tc : O(N)
// sc : O(N)

// N -> len of S (S = pattern + "$" + text);

class Solution {
public:
    vector<int> lpsFunc(string& str) {
        int n = str.length();

        vector<int> lps(n, 0);

        int i = 1, j = 0;

        while(i < n) {
            if(str[i] == str[j]) {
                lps[i] = j + 1;
                j++;
            }
            else {
                while(j > 0 && str[i] != str[j]) {
                    j = lps[j - 1];
                }

                if(str[i] == str[j]) {
                    lps[i] = j + 1;
                    j++;
                }
            }

            i++;
        }

        return lps;
    }

    vector<int> search(string pat, string txt) {
        string str = pat + "$" + txt;

        vector<int> lps = lpsFunc(str);

        vector<int> pos;
        int patlen = pat.length();
        
        for (int i = patlen + 1; i < lps.size(); i++) {
            if (lps[i] == patlen) {
                pos.push_back(i - (patlen + 1) - patlen + 1);
            }
        }

        return pos;
    }
};