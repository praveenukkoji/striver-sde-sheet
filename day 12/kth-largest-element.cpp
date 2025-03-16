// level - medium
// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

// tc : O(n * logn)
// sc : O(1)
// sorting and returning element at (k - 1) pos as arr is 0 based-indexed


// tc : O(n * logn)
// sc : O(1)

class Solution {
public:
    int countGreater(vector<int>& nums, int mid) {
        int count = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] >= mid)
                count++;
        }
        return count;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = (int)nums.size();

        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high) {
            int mid = (low + high) / 2;

            int count = countGreater(nums, mid);
            if(count < k) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return high;
    }
};


// tc : O(n * logk)
// sc : O(k)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int ele: nums) {
            minHeap.push(ele);

            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};