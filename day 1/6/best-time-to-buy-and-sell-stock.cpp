// level- easy
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

// tc : O(n)
// sc : O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        int buy = prices[0];

        for(int i=1;i<prices.size();i++) {
            if(prices[i] < buy) {
                buy = prices[i];
                continue;
            }

            if(prices[i] > buy) {
                profit = max(profit, prices[i]-buy);
            }
        }

        return profit;
    }
};