class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0];
        int mx = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            curr = max(curr + nums[i], nums[i]);
            mx = max(curr, mx);
        }
        return mx;
    }
};
