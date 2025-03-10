// level - medium
// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

// same as median-of-two-sorted-arrays

// tc : O(log(min(n1, n2)))
// sc : O(1)

class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n1 = (int)a.size();
        int n2 = (int)b.size();
        
        if(n1 > n2) return kthElement(b, a, k);
        
        int low = max(0, k - n2);
        int high = min(k, n1);
        int left = k;
        
        while(low <= high) {
            int mid1 = (low + high) / 2;
            int mid2 = k - mid1;
            
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            
            if(mid1 < n1) r1 = a[mid1];
            if(mid2 < n2) r2 = b[mid2];
            
            if(mid1 - 1 >= 0) l1 = a[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = b[mid2 - 1];
            
            if((l1 <= r2) && (l2 <= r1)) {
                return max(l1, l2);
            }
            
            if(l1 > r2) {
                high = mid1 - 1;
            }
            else {
                low = mid1 + 1;
            }
        }
        
        return -1;
    }
};