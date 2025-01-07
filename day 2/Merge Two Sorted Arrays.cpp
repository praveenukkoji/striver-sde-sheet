// level - 
// https://bit.ly/3BqXvPn

// tc : O(n+m)
// sc : O(n+m)

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	int aSize = a.size();
	int bSize = b.size();

	vector<long long> ans;

	int i=0;
	int j=0;

	while(i < aSize && j < bSize) {
		if(a[i] <= b[j]) {
			ans.push_back(a[i]);
			i++;
		}
		else {
			ans.push_back(b[j]);
			j++;
		}
	}

	while(j < bSize) {
		ans.push_back(b[j]);
		j++;
	}


	while(i < aSize) {
		ans.push_back(a[i]);
		i++;
	}

	for(auto &it : ans) {
		cout<<it<<" ";
	}
	cout<<endl;
}

// tc: O(n*logn) + O(m*logm) + O(min(n,m))
// sc : O(1)

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	int aInd = a.size() - 1;
	int bInd = 0;

	while(aInd >=0 && bInd < b.size()) {
		if(a[aInd] >= b[bInd]) {
			swap(a[aInd], b[bInd]);
		}
		aInd--, bInd++;
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
}