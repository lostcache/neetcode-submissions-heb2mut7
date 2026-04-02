class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<long long> pre(nums.size(), -1), post(nums.size(), -1);
        long long prePrd = 1;
        for (int i =0 ; i < nums.size(); ++i) {
            prePrd *= nums[i];
            pre[i] = prePrd;
        }

        long long postPrd = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            postPrd *= nums[i];
            post[i] = postPrd;
        }

        vector<int> res(nums.size(), 1);
        for (int i =0 ; i < nums.size(); ++i) {
            if (i - 1 >= 0) res[i] *= pre[i - 1];
            if (i + 1 < nums.size()) res[i] *= post[i + 1];
        }
        
        return res;
    }
};
