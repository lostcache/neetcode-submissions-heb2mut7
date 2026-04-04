class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int mxIdx = 0;
        for (int i = 0; i < n; ++i) {
            if (mxIdx < i) return false;
            mxIdx = max(mxIdx, i + nums[i]);
        }
        return true;
    }
};
