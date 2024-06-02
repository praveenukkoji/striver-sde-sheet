// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int max_profit = 0;
        int min_price = INT_MAX;

        for(int i=0;i<prices.size();i++) {
            min_price = min(min_price, prices[i]);
            max_profit = max(max_profit, prices[i] - min_price);
        }

        return max_profit;
    }
};