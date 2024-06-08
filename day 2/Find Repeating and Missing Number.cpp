// https://www.interviewbit.com/problems/repeat-and-missing-number-array/

// math equation method
pair<int,int> missingAndRepeating(vector<int> &a, int n1)
{    
    long long n = (long long) n1;
    long long sn = (n*(n+1))/2;
    long long s2n = (n*(n+1)*(2*n+1))/6;
    
    long long s = 0;
    long long s2 = 0;
    
    for(int i=0;i<n;i++) {
        s += a[i];
        s2 += (long long)a[i] * (long long)a[i];
    }
    
    long long val1 = s- sn;
    long long val2 = s2-s2n;
    val2 = val2/val1;
    
    long long x = (val1+val2)/2;
    long long y = x - val1;
    
    return {(int)y, (int)x};

}


// xor method
pair<int,int> missingAndRepeating(vector<int> &a, int n1)
{    
    long long n = (long long) n1;

    long long xr = 0;
    for(int i=0;i<n;i++) {
        xr = xr ^ a[i];
        xr = xr ^ (i+1);
    }

    // int bitNo = 0;
    // while(1) {
    //     if(xr & (1<<bitNo) != 0) {
    //         break;
    //     }
    //     bitNo++;
    // }

    int number = xr & ~(xr-1);

    int zero = 0;
    int one = 0;

    for(int i=0;i<n;i++) {
        // if((a[i] & (1<<bitNo)) != 0) {
        //     one = one ^ a[i];
        // }
        if((a[i] & number) != 0) {
            one = one ^ a[i];
        }
        else {
            zero = zero ^ a[i];
        }
    }
    for(int i=1;i<=n;i++) {
        // if((i & (1<<bitNo)) != 0) {
        //     one = one ^ i;
        // }
        if((i & number) != 0) {
            one = one ^ i;
        }
        else {
            zero = zero ^ i;
        }
    }

    int cnt = 0;
    for(int i=0;i<n;i++) {
        if(a[i] == one) cnt++;
    }

    if(cnt == 2) return {(int)zero, (int)one};
    return {(int)one, (int)zero};
}