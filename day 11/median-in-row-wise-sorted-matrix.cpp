// level - medium
// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

// tc : O(n*m + (n*m)log(n*m))
// sc : O(n*m)

class Solution {
public:
    int median(vector<vector<int>> &mat) {
        // code here
        vector<int> nums;
        for(auto& row: mat) {
            for(auto& ele: row) {
                nums.push_back(ele);
            }
        }
        
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

// tc : O(1e9) * O(m * logn)
// sc : O(1)


class Solution {
public:
    int getSmallerEquals(vector<vector<int>>& mat, int target) {
        int smallerEquals = 0;
        int rows = mat.size();
        for(int i=0;i<rows;i++) {
            smallerEquals += upper_bound(mat[i].begin(), mat[i].end(), target) - mat[i].begin();
        }
        return smallerEquals;
    }
    
    int median(vector<vector<int>> &mat) {
        // code here
        int rows = mat.size();
        int cols = mat[0].size();
        
        int low = INT_MAX, high = INT_MIN;
        for(int i=0;i<rows;i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][cols - 1]);
        }
        
        int required = (rows * cols) / 2;
        while(low <= high) {
            int mid = (low + high) / 2;
            
            int smallerEquals = getSmallerEquals(mat, mid);
            
            if(smallerEquals <= required) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        return low;
    }
};
  