class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, pair<int, int>>> p;
        for (const auto pi: points) {
            int x = pi[0], y = pi[1];
            p.push_back({x*x+y*y, {x, y}});
        }
        sort(p.begin(), p.end());
        vector<vector<int>> res;
        for (int i = 0; i < k; ++i) {
            auto pi = p[i].second;
            res.push_back({pi.first, pi.second});
        }
        return res;
    }
};
