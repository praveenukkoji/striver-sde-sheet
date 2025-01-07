// level -
// https://bit.ly/3MC5iAx

// tc : O(2*n)
// sc : O(n+1)

vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
	int n = a.size();

	vector<int> freq(n+1, 0);

	for(int i=0;i<n;i++) {
		freq[a[i]] += 1;
	}

	int p = -1, q = -1;

	for(int i=0;i<n+1;i++) {
		if(freq[i] == 2) {
			p = i;
		}
		else if(freq[i] == 0) {
			q = i;
		}
	}

	return {p, q};
}

// tc : O(n)
// sc : O(1)

vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
	long long n = a.size();

	long long sn = (n*(n+1))/2;
    long long s2n = (n*(n+1)*(2*n+1))/6;

    long long sum = 0;
    long long sum2 = 0;

    for(int i=0;i<n;i++) {
        sum += a[i];
        sum2 += (long long)a[i] * (long long)a[i];
    }

    long long diff1 = sum - sn;
    long long diff2 = sum2 - s2n;

    diff2 = diff2 / diff1;

    long long p = (diff1 + diff2)/2;
    long long q = p - diff1;

    return{p, q};
}

// tc : O(n)
// sc : O(1)

vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
    int n = a.size();
	int xr = 0;

    for(int i=0;i<n;i++) {
        xr ^= a[i];
        xr ^= i+1;
    }

    int bitNo = 0;

    while(1) {
        if((xr & (1<<bitNo)) != 0) {
            break;
        }
        bitNo++;
    }

    int zeroClub = 0;
    int oneClub = 0;

    for(int i=0;i<n;i++) {
        if((a[i] & (1<<bitNo)) != 0) {
            oneClub ^= a[i];
        }
        else {
            zeroClub ^= a[i];
        }
    }

    for(int i=1;i<=n;i++) {
        if((i & (1<<bitNo)) != 0) {
            oneClub ^= i;
        }
        else {
            zeroClub ^= i;
        }
    }

    int cnt = 0;
    for(int i=0;i<n;i++) {
        if(a[i] == zeroClub) cnt++;
    }

    if(cnt == 2) {
        return {zeroClub, oneClub};
    }

    return {oneClub, zeroClub};
}