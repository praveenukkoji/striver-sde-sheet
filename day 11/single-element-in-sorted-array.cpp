// level - medium
// https://leetcode.com/problems/single-element-in-a-sorted-array/description/

// tc : O(n)
// sc : O(1)

int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); //size of the array.
    if (n == 1) return arr[0];

    for (int i = 0; i < n; i++) {

        //Check for first index:
        if (i == 0) {
            if (arr[i] != arr[i + 1])
                return arr[i];
        }
        //Check for last index:
        else if (i == n - 1) {
            if (arr[i] != arr[i - 1])
                return arr[i];
        }
        else {
            if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
                return arr[i];
        }
    }

    // dummy return statement:
    return -1;
}

// tc : O(n)
// sc : O(1)

int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); //size of the array.
    int ans = 0;
    // XOR all the elements:
    for (int i = 0; i < n; i++) {
        ans = ans ^ arr[i];
    }
    return ans;
}

// tc : O(logn)
// sc : O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = (int)nums.size();

        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        int low = 1, high = n - 1;
        while(low <= high) {
            int mid = (low + high) / 2;

            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];

            if((mid % 2 == 0 && nums[mid] == nums[mid - 1]) ||
                (mid % 2 != 0 && nums[mid] == nums[mid + 1])) {
                    high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return -1;
    }
};