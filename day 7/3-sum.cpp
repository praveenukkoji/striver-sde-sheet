// level - medium
// https://leetcode.com/problems/3sum/description/

// tc : O(n^3)
// sc : O(2*no_of_unique_triplets)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        set<vector<int>> ans;

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i == j) continue;
                for(int k=0;k<n;k++) {
                    if(i == k || j == k) continue;

                    if((nums[i] + nums[j] + nums[k]) == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        ans.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>> ans1(ans.begin(), ans.end());
        return ans1;
    }
};

// tc : O(N^2 * log(no. of unique triplets))
// sc : O(2 * no. of the unique triplets) + O(N)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        set<vector<int>> st;

        for(int i=0;i<n;i++) {
            set<int> hasSet;

            for(int j=i+1;j<n;j++) {
                int third = -(nums[i]+nums[j]);

                if(hasSet.find(third) != hasSet.end()) {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }

                hasSet.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

// tc : O(nlogn) + O(n^2)
// sc : O(1)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i=0;i<n;i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int j = i+1;
            int k = n-1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if(sum > 0) {
                    k--;
                }
                else if(sum < 0) {
                    j++;
                }
                else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);

                    j++;
                    k--;

                    while(j < k && nums[j-1] == nums[j]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }

        return ans;
    }
};