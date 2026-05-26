class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> arr(nums.size() + 2, 0);
        arr[0] = 1;
        arr[arr.size() - 1] = 1;
        for (int i = 1; i <= nums.size(); ++i) {
            arr[i] = nums[i - 1];
        }

        vector<vector<int>> dp(nums.size() + 2, vector<int>(nums.size() + 2, 0));

        for (int l = nums.size(); l > 0; --l) {
            for (int r = l; r <= nums.size(); ++r) {
                for (int i = l; i <= r; ++i) {
                    dp[l][r] = max({
                        dp[l][r],
                        dp[l][i - 1] + arr[l - 1] * arr[i] * arr[r + 1] + dp[i + 1][r]
                    });
                }
            }
        }

        return dp[1][nums.size()];
    }
};