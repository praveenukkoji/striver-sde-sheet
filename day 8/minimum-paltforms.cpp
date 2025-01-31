// level - medium 
// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

// tc : O(n * log(n))
// sc : O(1)

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int n = (int)arr.size();
        
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int currPlatform = 1;
        int maxPlatform = 1;
        
        int arrPos = 1;
        int depPos = 0;
        
        while(arrPos < n && depPos < n) {
            if(arr[arrPos] <= dep[depPos]) {
                currPlatform++;
                arrPos++;
            }
            else if(arr[arrPos] > dep[depPos]) {
                depPos++;
                currPlatform--;
            }
            
            maxPlatform = max(maxPlatform, currPlatform);
        }
        
        return maxPlatform;
    }
};