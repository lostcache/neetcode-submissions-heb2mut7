class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0

        dp = [float('inf') for _ in range(amount + 1)]

        for ci in coins:
            if ci > amount:
                continue
            dp[ci] = 1

        for i in range(amount + 1):
            if (dp[i] == -1):
                continue

            for ci in coins:
                if i + ci > amount:
                    continue
                
                dp[i + ci] = min(dp[i + ci], 1 + dp[i])
        
        if dp[amount] == float('inf'):
            return -1

        return dp[amount]