class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

        for (int i = 0; i < k - 1; ++i) {
            pq.push({nums[i], i});
        }

        for (int r = k - 1; r < nums.size(); ++r) {
            pq.push({nums[r], r});

            auto [mx, mxi] = pq.top();
            while (mxi < (r - k + 1)) {
                pq.pop();
                const auto& cp = pq.top();
                mx = cp.first;
                mxi = cp.second;
            }

            res.push_back(mx);
        }

        return res;
    }
};
