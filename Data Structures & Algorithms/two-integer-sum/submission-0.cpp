class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> targetMinusNum;
        for (int i = 0; i < nums.size(); ++i) {
            if (targetMinusNum[target - nums[i]]) {
                return { targetMinusNum[target - nums[i]] - 1, i };
            }
            targetMinusNum[nums[i]] = i + 1;
        }
        return { -1, -1 };
    }
};
