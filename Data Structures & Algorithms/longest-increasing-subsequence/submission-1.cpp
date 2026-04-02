class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            int curr = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    curr = max(curr, dp[j]);
                }
            }
            dp[i] = 1 + curr;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
