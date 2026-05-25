class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> arr(nums.size() + 2, 0);
        arr[0] = 1;
        arr[arr.size() - 1] = 1;
        for (int i = 1; i <= nums.size(); ++i) {
            arr[i] = nums[i - 1];
        }

        map<pair<int, int>, int> memo;

        auto dfs = [&](auto&& self, int l, int r) {
            if (l > r) return 0;

            if (memo.find({l, r}) != memo.end()) {
                return memo[{l, r}];
            }

            int score = 0;
            for (int i = l; i <= r; ++i) {
                score = max({
                    score,
                    arr[l - 1] * arr[i] * arr[r + 1] + self(self, l, i - 1) + self(self, i + 1, r)
                });
            }

            memo[{l, r}] = score;
            return score;
        };

        return dfs(dfs, 1, nums.size());
    }
};