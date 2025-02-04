// level - hard
// https://leetcode.com/problems/permutation-sequence/description/

// tc : O(n!n + n!nlogn)=O(n! nlogn)
// sc : O(n * n!)

class Solution {
public:
    void generatePermutations(string& s, int index, vector<string>& res) {
        if (index == s.size()) {
            res.push_back(s);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            swap(s[i], s[index]);
            generatePermutations(s, index + 1, res);
            swap(s[i], s[index]);
        }
    }

    string getPermutation(int n, int k) {
        string s;
        vector<string> res;
        // create string containing all  numbers 1 to n
        for (int i = 1; i <= n; i++) {
            s.push_back(i + '0');
        }

        generatePermutations(s, 0, res);
        
        // sort them in order so that we can retrive kth permutation
        sort(res.begin(), res.end());

        // since res is 0-based return (k-1)th
        return res[k-1];
    }
};

// Time Complexity: O(N) * O(N) = O(N^2)
// Reason: We are placing N numbers in N positions. This will take O(N) time. 
// For every number, we are reducing the search space by removing the element already placed in the previous step.
// This takes another O(N) time.

// Space Complexity: O(N)
// Reason: We are storing  the numbers in a data structure(here vector)

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        for(int i=1;i<n;i++) {
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        string ans = "";
        k = k - 1;

        while(fact) {
            int group = k / fact;
            ans += to_string(numbers[group]);
            numbers.erase(numbers.begin() + group);
            if(numbers.size() == 0) {
                break;
            }
            k = k % fact;
            fact = fact / numbers.size();
        }

        return ans;
    }
};