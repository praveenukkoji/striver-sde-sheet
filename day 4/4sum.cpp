// level - medium
// https://leetcode.com/problems/4sum/description/

// tc : O(n^4)
// sc : O(1)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        set<vector<int> > st;

        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {
                    for(int l=k+1;l<n;l++) {
                        long long sum = nums[i]+nums[j];
                        sum+= nums[k];
                        sum += nums[l];
                        if(target == sum) {
                            st.insert({nums[i],nums[j],nums[k],nums[l]});
                        }
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

// tc : O(n^3*logm) m->no of element present in hashset
// sc : O(2 * no. of the quadruplets)+O(N)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        set<vector<int> > ans;

        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                set<long long> hashset;

                for(int k=j+1;k<n;k++) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];

                    long long fourth = target - sum;

                    if(hashset.find(fourth) != hashset.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                        sort(temp.begin(), temp.end());
                        ans.insert(temp);
                    }

                    hashset.insert(nums[k]);
                }
            }
        }

        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};

// tc : O(n^3)
// sc : O(1)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for(int i=0;i<n;i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j=i+1;j<n;j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j+1;
                int right = n-1;

                while(left < right) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[left];
                    sum += nums[right];

                    if(sum == (1LL * target)) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    }
                    else if(sum < (1LL * target)) {
                        left++;
                    }
                    else {
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};