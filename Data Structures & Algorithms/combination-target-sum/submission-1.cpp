class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> s;
        helper(0, 0, target, nums, s, res);
        return res;
    }

private:
    void helper(int idx, int v, int target, vector<int>& nums, vector<int>& s, vector<vector<int>>& res) {
        if (idx >= nums.size() || v > target) return;

        if (v == target) {
            res.push_back(s);
            return;
        }

        s.push_back(nums[idx]);
        helper(idx, v + nums[idx], target, nums, s, res);
        s.pop_back();

        helper(idx + 1, v, target, nums, s, res);
        
    }
};
