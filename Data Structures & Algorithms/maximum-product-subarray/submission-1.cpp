class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> pre(nums.size(), 0), post(nums.size(), 0);
        pre[0] = nums[0];
        post[nums.size() - 1] = nums[nums.size() - 1];
        int res = max(nums[0], nums[nums.size() - 1]);
        for (int i = 1; i < nums.size(); ++i) {
            cout << nums.size() - 1 - i << ' ' << nums.size() - i << endl;
            pre[i] = pre[i - 1] == 0 ? nums[i] : nums[i] * pre[i - 1];
            post[nums.size() - 1 - i] = post[nums.size() - i] == 0 ?
                nums[nums.size() - 1 - i] : nums[nums.size() - 1 - i] * post[nums.size() - i];
            res = max(res, max(pre[i], post[nums.size() - 1 - i]));
        }           
        return res;
    }
};
