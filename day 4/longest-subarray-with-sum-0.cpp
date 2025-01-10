// level - medium
// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

// tc : O(n)
// sc : O(n)

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int n = arr.size();
        
        map<int, int> prefix;
        
        int maxLen = 0;
        long long sum = 0;
        
        for(int i=0;i<n;i++) {
            sum += arr[i];
            
            if(sum == 0) {
                maxLen = i+1;
            }
            else {
                if(prefix.find(sum) != prefix.end()) {
                    maxLen = max(maxLen, i - prefix[sum]);
                }
                else {
                    prefix[sum] = i;
                }
            }
        }
        
        return maxLen;
    }
};