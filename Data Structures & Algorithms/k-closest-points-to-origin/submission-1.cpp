class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>, less<pair<int, pair<int, int>>>> q;
        for (const auto& p: points) {
            int x = p[0], y = p[1];
            q.push({x*x+y*y, {x, y}});
            if (q.size() > k) {
                q.pop();
            }
        }
        vector<vector<int>> res;
        while (!q.empty()) {
            auto p = q.top().second;
            res.push_back({p.first, p.second});
            q.pop();
        }
        return res;
    }
};
