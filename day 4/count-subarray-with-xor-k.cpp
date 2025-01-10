// level - hard
// https://www.interviewbit.com/problems/subarray-with-given-xor/

// tc : O(n^2)
// sc : O(n)

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    
    unordered_map<int, int> prefix;
    
    int cnt = 0;
    
    for(int i=0;i<n;i++) {
        int x = 0;
        
        for(int j=i;j<n;j++) {
            
            x ^= A[j];
            
            if(x == B) cnt += 1;
        }
    }
    
    return cnt;
}

// tc : O(n)
// sc : O(n)

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    
    int x = 0;
    
    unordered_map<int, int> mp;
    mp[x] = 1;
    
    int cnt = 0;
    
    for(int i=0;i<n;i++) {
        x = x ^ A[i];
        cnt += mp[x^B];
        mp[x]++;
    }
    
    return cnt;
}
