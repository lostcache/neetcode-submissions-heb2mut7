class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> eleFreq;
        for (const auto num: nums) {
            eleFreq[num]++;
        }

        vector<pair<int, int>> freqEle;
        freqEle.reserve(nums.size());
        for (const auto [ele, fre]: eleFreq) {
            freqEle.push_back({fre, ele});
        }

        sort(freqEle.begin(), freqEle.end(), greater<>());

        vector<int> res;
        res.reserve(k);
        for (int i = 0; i < k; ++i) {
            res.push_back(freqEle[i].second);
        }

        return res;
    }
};
