class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr = INT_MAX;
        int profit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] > curr) {
                profit += prices[i] - curr;
                curr = prices[i];
            }
            curr = min(curr, prices[i]);
        }
        return profit;
    }
};