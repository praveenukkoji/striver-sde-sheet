// level - 
// https://bit.ly/3pAeTyp

// tc : O(n*logn) + O(2*n)
// sc : O(n)

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	// Write your code here.
	int n = arr.size();
	vector<vector<int>> ans;

	for(int i=0;i<n;i++) {
		int start = arr[i][0];
		int end = arr[i][1];

		if(!ans.empty() && end <= ans.back()[1]) {
			continue;
		}

		for(int j=i+1;j<n;j++) {
			if(end >= arr[j][0]) {
				end = max(end, arr[j][1]);
			}
			else {
				break;
			}
		}

		ans.push_back({start,end});
	}

	return ans;
}

// tc : O(n*logn) + O(n)
// sc : O(n)

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	// Write your code here.
	int n = arr.size();
	vector<vector<int>> ans;
	ans.push_back({arr[0][0], arr[0][1]});

	for(int i=1;i<n;i++) {
		int start = arr[i][0];
		int end = arr[i][1];

		if(ans.back()[1] >= start) {
			ans.back()[1] = max(end, ans.back()[1]);
		}
		else {
			ans.push_back({start, end});
        }
    }

	return ans;
}