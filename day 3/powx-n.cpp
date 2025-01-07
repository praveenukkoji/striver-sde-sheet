// level - medium
// https://leetcode.com/problems/powx-n/description/

// tc : O(n)
// sc : O(1)

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;

        long long newN = n;
        if(newN < 0) {
            newN = (long long)(-1) * n;
        }

        while(newN--) {
            ans *= x;
        }

        if(n < 0) return 1/ans;

        return ans;
    }
};

// tc : O(log(n))
// sc : O(1)

// Binary Exponentiation
class Solution {
public:
    double myPow(double x, int n) {
        long long newN = n;

        double ans = 1.0;

        if(newN < 0) newN = (-1) * newN;

        while(newN != 0) {
            if(newN%2 != 0) {
                ans *= x;
                newN--;
            }
            else {
                x = x * x;
                newN /= 2;
            }
        }

        if(n < 0) return 1/ans;

        return ans;
    }
};