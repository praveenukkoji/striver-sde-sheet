// level - medium
// https://www.naukri.com/code360/problems/next-smaller-element_1112581

// tc : O(n)
// sc : O(n)

#include <bits/stdc++.h>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> st;
    vector<int> nse(n, -1);

    for(int i=n-1;i>=0;i--) {
        while(!st.empty() && arr[i] <= st.top()) {
            st.pop();
        }

        if(!st.empty())
            nse[i] = st.top();
        
        st.push(arr[i]);
    }

    return nse;
}