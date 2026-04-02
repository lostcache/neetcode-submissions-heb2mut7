class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            int robbed = nums[i];
            if (i - 2 >= 0) robbed += dp[i - 2];
            int not_robbed = dp[i - 1];
            dp[i] = max(robbed, not_robbed);
        }
        return dp[nums.size() - 1];
    }
};
