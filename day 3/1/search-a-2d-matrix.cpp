// level - medium
// https://leetcode.com/problems/search-a-2d-matrix/description/

// tc : O(n*m)
// sc : O(1)

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(mat[i][j] == target) return true;
        }
    }

    return false;
}

// tc : O(n*log(m))
// sc : O(1)

bool binarySearch(vector<int>& mat, int target) {
    int low = 0, high = mat.size();

    while(low <= high) {
        int mid = (low + high) / 2;

        if(mat[mid] == target) return true;

        else if(target > mat[mid]) low = mid + 1;

        else high = mid - 1;
    }

    return false;
}

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();

    for(int i=0;i<n;i++) {
        if(mat[i][0] <= target && target <= mat[i][m-1]) {
            if(binarySearch(mat[i], target)) {
                return true;
            }
        }
    }

    return false;
}

// tc : O(log(n*m))
// sc : O(1)

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();

    int low = 0, high = n * m -1;

    while(low <= high) {
        int mid = (low + high) / 2;

        int row = mid / m;
        int col = mid % m;

        if(mat[row][col] == target) {
            return true;
        }

        else if(target > mat[row][col]) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    return false;
}