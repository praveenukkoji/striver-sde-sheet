// level - easy
// https://www.naukri.com/code360/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// tc : O(n * m)
// sc : O(1)
// if we do it using linear search


// tc : O(n * log m)
// sc : O(1)

int solve(int mid, int n, int m) {
  long long ans = 1;
  for(int i=0;i<n;i++) {
    ans *= mid;
    if(ans > m) return 2;
  }

  if(ans == m) return 1;

  return 0;
}

int NthRoot(int n, int m) {
  // Write your code here.
  int low = 1;
  int high = m;

  while(low <= high) {
    int mid = low + (high - low) / 2;
    
    int flag = solve(mid, n, m);

    if(flag == 1) {
      return mid;
    }
    else if(flag == 2) {
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }

  return -1;
}