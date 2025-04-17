// level - medium
// 

// tc : O(n)
// sc : O(n)

vector<int> Solution::prevGreater(vector<int> &A) {
    int n = A.size();
    
    stack<int> st;
    vector<int> pge(n, -1);
    
    for(int i=0;i<n;i++) {
        while(!st.empty() && A[i] >= st.top()) {
            st.pop();
        }
        
        if(!st.empty())
            pge[i] = st.top();
        
        st.push(A[i]);
    }
    
    return pge;
}
