class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, less<vector<int>>> q;
        for (const auto& p: points) {
            int x = p[0], y = p[1];
            q.push({x*x+y*y, x, y});
            if (q.size() > k) {
                q.pop();
            }
        }
        vector<vector<int>> res;
        while (!q.empty()) {
            auto p = q.top();
            res.push_back({p[1], p[2]});
            q.pop();
        }
        return res;
    }
};
