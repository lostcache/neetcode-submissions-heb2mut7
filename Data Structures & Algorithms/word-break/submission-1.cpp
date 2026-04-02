class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp (s.length() + 1, false);
        dp[0] = true;
        for (int i = 0; i < s.length(); ++i) {
            if (!dp[i]) continue;
            for (const auto& wi: wordDict) {
                if (s.substr(i).starts_with(wi)) {
                    dp[i + wi.length()] = true;
                }
            }
        }
        return dp[s.length()];
    }
};
