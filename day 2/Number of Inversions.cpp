// level -
// https://www.codingninjas.com/codestudio/problems/number-of-inversions_6840276?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems

// tc : O(n^2)
// sc : O(1)

int numberOfInversions(vector<int>&a, int n) {
    // Write your code here.
    int cnt = 0;

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(a[i] > a[j]) cnt++;
        }
    }

    return cnt;
}

// tc : O(n*logn)
// sc : O(n)

int merge(vector<int> &a, int low, int mid, int high) {
    vector<int > temp;

    int left = low;
    int right = mid+1;

    int cnt = 0;

    while(left <= mid && right <= high) {
        if(a[left] <= a[right]) {
            temp.push_back(a[left]);
            left++;
        }
        else {
            cnt += (mid - left + 1);
            temp.push_back(a[right]);
            right++;
        }
    }

    while(left <= mid)  {
        temp.push_back(a[left]);
        left++;
    }

    while(right <= high) {
        temp.push_back(a[right]);
        right++;
    }

    for(int i=low;i<=high;i++) {
        a[i] = temp[i - low];
    }

    return cnt;
}

int mergeSort(vector<int>& a, int low, int high) {
    int cnt = 0;

    if(low >= high) return cnt;

    int mid = (low + high) / 2;

    cnt += mergeSort(a, low, mid);
    cnt += mergeSort(a, mid+1, high);

    cnt += merge(a, low, mid, high);

    return cnt;
}

int numberOfInversions(vector<int>&a, int n) {
    // Write your code here.
    return mergeSort(a, 0, n-1);
}