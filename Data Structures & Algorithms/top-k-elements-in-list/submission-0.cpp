class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> fre;
        for (int i = 0; i < nums.size(); ++i) {
            fre[nums[i]]++;
        }

        vector<pair<int, int>> p;
        for (auto [ele, cnt]: fre) {
            p.push_back({cnt, ele});
        }

        vector<int> res;
        sort(p.rbegin(), p.rend());
        for (int i = 0; i < k; ++i) {
            res.push_back(p[i].second);
        }

        return res;
    }
};
