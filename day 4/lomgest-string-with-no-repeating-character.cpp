// level - medium
// 

// tc : O(n^2)
// sc : O(256)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int maxLen = 0;

        for(int i=0;i<n;i++) {
            vector<int> hash(256, 0);

            for(int j=i;j<n;j++) {
                if(hash[s[j]] == 1) break;

                int currLen = j-i+1;
                maxLen = max(maxLen, currLen);

                hash[s[j]] = 1;
            }
        }

        return maxLen;
    }
};

// tc : O(n)
// sc : O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        
        unordered_map<char, int> mp;

        int maxLen = 0;
        int currLen = 0;
        
        while(right < s.length()) {
            if(mp.find(s[right]) != mp.end()) {
                left = max(mp[s[right]] + 1, left);
            }
            currLen = right - left + 1;
            maxLen = max(maxLen, currLen);
            mp[s[right]] = right;
            right++;
        }

        return maxLen;
    }
};