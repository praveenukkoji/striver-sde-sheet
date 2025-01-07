// level - hard
// https://leetcode.com/problems/reverse-pairs/description/

// tc : O(n^2)
// sc : O(1)

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0;

        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                if(nums[i] > (2*(long long)nums[j])) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

// tc : O(n*logn)
// sc : O(1)

class Solution {
public:
    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        temp.reserve(high - low + 1);

        int left = low;
        int right = mid+1;

        while(left <= mid && right <= high) {
            if(arr[left] > arr[right]) {
                temp.push_back(arr[right]);
                right++;
            }
            else {
                temp.push_back(arr[left]);
                left++;
            }
        }

        while(left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        while(right<= high) {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = 0; i < temp.size(); i++) {
            arr[low + i] = temp[i];
        }
    }

    int countPairs(vector<int>& arr, int low, int mid, int high) {
        int cnt = 0;

        int left = low;
        int right = mid+1;

        for(int i=left;i<=mid;i++) {
            while (right <= high && arr[i] > (long)2 * arr[right]) right++;
            cnt += right - (mid + 1);
        }

        return cnt;
    }

    int mergeSort(vector<int>& arr, int low , int high) {
        int cnt = 0;

        if(low >= high) return cnt;

        int mid = (low+high)/2;

        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid+1, high);
        cnt += countPairs(arr, low, mid, high);

        merge(arr, low, mid, high);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        // vector<int> temp = nums;

        // int n = temp.size();

        return mergeSort(nums, 0, nums.size()-1);
    }
};