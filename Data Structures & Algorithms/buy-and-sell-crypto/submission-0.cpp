class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_price = INT_MAX;
        int profit = 0;
        for (const int price: prices) {
            if (price < buy_price) {
                buy_price = price;
            } else {
                profit = max(profit, price - buy_price);
            }
        }

        return profit;
    }
};
