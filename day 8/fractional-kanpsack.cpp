// level - medium
// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

// tc : O(2 * n) + O(n * log(n))
// sc : O(n)

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Your code here
        vector<pair<int, int>> given;
        for(int i=0;i<val.size();i++) {
            given.push_back(make_pair(val[i], wt[i]));
        }
        
        sort(given.begin(), given.end(), [](const auto& a, const auto& b) {
            return (a.first/(double)a.second) > (b.first/(double)b.second);
        });
        
        // for(const auto& it: given) {
        //     cout<<it.first<<" - "<<it.second<<endl;
        // }
        
        int currCapacity = 0;
        double value = 0.0;
        int i = 0;
        
        while(i<given.size()) {
            if((currCapacity + given[i].second) <= capacity) {
                currCapacity += given[i].second;
                value += given[i].first;
            }
            else {
                double remCap = capacity - currCapacity;
                value += (given[i].first/(double)given[i].second) * remCap;
                break;
            }
            
            i++;
        } 
        
        return value;
    }
};