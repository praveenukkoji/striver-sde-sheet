// level - medium
// https://www.interviewbit.com/problems/nearest-smaller-element/

// tc : O(n)
// sc : O(n)

vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    
    stack<int> st;
    vector<int> pse(n, -1);
    
    for(int i=0;i<n;i++) {
        while(!st.empty() && A[i] <= st.top()) {
            st.pop();
        }
        
        if(!st.empty())
            pse[i] = st.top();
        
        st.push(A[i]);
    }
    
    return pse;
}
