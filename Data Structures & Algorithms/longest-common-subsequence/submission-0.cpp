class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1;
                    if (i + 1 < m && j + 1 < n) dp[i][j] += dp[i + 1][j + 1];
                } else {
                    int keep_first = 0, keep_second = 0;
                    if (j + 1 < n) keep_first = dp[i][j + 1];
                    if (i + 1 < m) keep_second = dp[i + 1][j];
                    dp[i][j] = max(keep_first, keep_second);
                }
            }
        }
        return dp[0][0];
    }
};
