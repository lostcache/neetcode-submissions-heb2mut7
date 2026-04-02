class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        curr = float('INF')
        profit = 0
        for i in range(len(prices)):
            if (prices[i] > curr):
                profit += prices[i] - curr
                curr = prices[i]
            curr = min(curr, prices[i])
        return profit
