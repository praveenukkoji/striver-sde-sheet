// level - medium
// https://www.naukri.com/code360/problems/max-of-min_982935?leftPanelTabValue=PROBLEM

// tc : O(n) nse + O(n) pse + O(n) ans
// sc : O(n + n) nse + O(n + n) pse + O(n) ans

#include <bits/stdc++.h> 

vector<int> getNse(vector<int>& arr) {
    int n = arr.size();

    stack<int> st;
    vector<int> nse(n, n);

    for(int i=n-1;i>=0;i--) {
        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        if(!st.empty()) 
            nse[i] = st.top();

        st.push(i);
    }

    return nse;
}

vector<int> getPse(vector<int>& arr) {
    int n = arr.size();

    stack<int> st;
    vector<int> pse(n, -1);

    for(int i=0;i<n;i++) {
        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        if(!st.empty())
            pse[i] = st.top();
        
        st.push(i);
    }

    return pse;
}

vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> nse = getNse(a);
    vector<int> pse = getPse(a);

    vector<int> ans(n, INT_MIN);
    for(int i = 0; i < n; i++) {
        int len = nse[i] - pse[i] - 1;
        ans[len - 1] = max(ans[len - 1], a[i]);
    }

    for(int i = n - 2; i >= 0; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    return ans;
}