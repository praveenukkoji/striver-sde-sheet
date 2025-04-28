// level - easy
// https://leetcode.com/problems/valid-anagram/description/

// tc : O(n*logn)
// sc : O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};

// tc : O(max_len(s, t))
// sc : O(max_len(s, t))

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() < t.length()) 
            swap(s, t);
    
        unordered_map<char, int> freq;
        for (char& ch : s) {
            freq[ch]++;
        }
        for (char& ch : t) {
            if (freq.find(ch) == freq.end()) {
                return false;
            }

            freq[ch]--;
        }

        for (auto [k, v] : freq) {
            if (v != 0) {
                return false;
            }
        }
        return true;
    }
};