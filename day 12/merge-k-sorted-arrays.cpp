// level - medium
// https://www.naukri.com/code360/problems/merge-k-sorted-arrays_975379

// tc : O(n * logn)
// sc : O(n)

#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    int r = (int)kArrays.size();

    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0;i<r;i++) {
        for(int j=0;j<kArrays[i].size();j++) {
            pq.push(kArrays[i][j]);
        }
    }

    vector<int> ans;
    while(!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}