class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        vector<int> dp(amount + 1, INT_MAX);
        for (auto ci: coins) {
            if (ci <= amount) dp[ci] = 1;
        }

        for (int i = 1; i <= amount; ++i) {
            if (dp[i] == INT_MAX) continue;
            for (auto ci: coins) {
                if (1LL * i + ci <= amount) {
                    dp[i + ci] = min(dp[i + ci], 1 + dp[i]);
                }
            }
        }

        if (dp[amount] == INT_MAX) {
            return -1;
        }

        return dp[amount];
    }
};
