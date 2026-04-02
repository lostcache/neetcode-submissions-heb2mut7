class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 0) return 0;
        sort(nums.begin(), nums.end());
        
        map<int, int> seen;
        seen[nums[0]] = 1;

        int res = 1;
        for (int i = 0; i < nums.size(); ++i) {
            seen[nums[i]] = seen[nums[i] - 1] + 1;
            res = max(res, seen[nums[i]]);
        }

        return res;
    }
};
