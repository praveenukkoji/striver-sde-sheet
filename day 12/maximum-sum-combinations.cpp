// level - medium
// https://www.interviewbit.com/problems/maximum-sum-combinations/

// Operation	    Time Complexity	        Space Complexity
// Sorting	        O(N log N)	            O(1) (in-place)
// Heap Operations	O(C log C)	            O(C)
// Set Operations	O(C log C)	            O(C)
// Result Vector	O(C)	                O(C)
// Overall	        O(N log N + C log C)	O(C)

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = (int)A.size();
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    priority_queue<pair<long long, pair<int, int>>> pq;
    pq.push({A[n-1]+B[n-1], {n-1, n-1}});
    
    set<pair<int, int>> inds;  
    inds.insert({n-1, n-1});
      
    vector<int> ans;
    
    while(C--) {
        long long sum = pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        
        pq.pop();
        
        ans.push_back(sum);
        
        if((j - 1) >= 0 && inds.find({i, j-1}) == inds.end()) {
            pq.push({A[i]+B[j-1], {i, j-1}});
            inds.insert({i, j-1});
        }
        if((i - 1) >= 0 && inds.find({i-1, j}) == inds.end()) {
            pq.push({A[i-1]+B[j], {i-1, j}});
            inds.insert({i-1, j});
        }
    }
    
    return ans;
}

// Operation	        Time Complexity	        Space Complexity
// Sorting	            O(N log N)	            O(1) (in-place)
// Initial Heap Build	O(N log N)	            O(N)
// Heap Operations	    O(C log N)	            O(N)
// Result Vector	    O(C)	                O(C)
// Overall	            O(N log N + C log N)	O(N + C)

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    vector<int> ans;
    priority_queue<pair<int, int> > pq;
    
    int N = A.size();
    
    for(int i=0;i<N;i++){
        int sum = A[i]+B[N-1];
        pq.push(make_pair(sum, N-1));
    }
    
    while(!pq.empty() && C--) {
        int sum = pq.top().first;
        int ind = pq.top().second;
        
        pq.pop();
        ans.push_back(sum);
        
        if(ind -1 >= 0) {
            pq.push(make_pair(sum-B[ind]+B[ind-1], ind - 1));
        }
    }
    
    return ans;
}