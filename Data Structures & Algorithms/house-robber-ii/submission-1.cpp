class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> n1, n2;
        vector<int> dp1(nums.size() - 1, 0), dp2(nums.size() - 1, 0);
        for (int i = 0; i < nums.size() - 1; ++i) {
            n1.push_back(nums[i]);
            n2.push_back(nums[i + 1]);
        }
        for (int i = 0; i < nums.size() - 1; ++i) {
            int robbed = n1[i];
            if (i - 2 >= 0) robbed += dp1[i - 2];
            int not_robbed = dp1[i - 1];
            dp1[i] = max(robbed, not_robbed);
        }
        for (int i = 0; i < nums.size() - 1; ++i) {
            int robbed = n2[i];
            if (i - 2 >= 0) robbed += dp2[i - 2];
            int not_robbed = dp2[i - 1];
            dp2[i] = max(robbed, not_robbed);
        }
        return max(dp1[nums.size() - 2], dp2[nums.size() - 2]);
    }
};
