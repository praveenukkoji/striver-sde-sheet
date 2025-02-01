// level - medium
// https://www.geeksforgeeks.org/problems/subset-sums2234/1

// tc : O(2^n) + O((2^n) log(2^n))
// sc : O(2^n)

class Solution {
  public:
    void getSums(int ind, int sum, vector<int>& arr, int n, vector<int>& ans) {
        if(ind == n) {
            ans.push_back(sum);
            return;
        }
        
        // pick
        getSums(ind+1, sum+arr[ind], arr, n, ans);
        
        // not pick
        getSums(ind+1, sum, arr, n, ans);
    }
    
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> ans;
        getSums(0, 0, arr, arr.size(), ans);
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};