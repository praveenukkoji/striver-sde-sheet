// level - medium
// https://www.naukri.com/code360/problems/aggressive-cows_1082559

// has both brute and optimal solution

// linear
// tc : O(NlogN) + O(N *(max(stalls[])-min(stalls[])))
// sc : O(1)

// binary
// tc : O(NlogN) + O(N * log(max(stalls[])-min(stalls[])))
// sc : O(1)

bool isPossible(vector<int>& stalls, int k, int dist) {
    int n = stalls.size();
    int cows = 1;
    int prevPlaced = stalls[0];

    for(int i=1;i<n;i++) {
        if((stalls[i] - prevPlaced) >= dist) {
            prevPlaced = stalls[i];
            cows++;
        }

        if(cows == k)
            return true;
    }

    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    // Write your code here.
    int n = (int)stalls.size();

    if(n < k) return 0;

    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls[n-1] - stalls[0];

    // linear
    // int ans = 0;
    // for(int dist=low;dist<=high;dist++) {
    //     if(isPossible(stalls, k, dist)) {
    //         ans = dist;
    //     }
    // }
    // return ans;

    // binary
    while(low <= high) {
        int mid = (low + high) / 2;

        if(isPossible(stalls, k, mid)) {
            low = mid + 1;
        }
        else { 
            high = mid - 1;
        }
    }

    return high;
}