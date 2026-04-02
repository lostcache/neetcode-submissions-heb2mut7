class Solution {
private:
    bool helper(const auto& adj, auto& vst, int p, int i) {
        if (vst[i]) return false;

        vst[i] = true;

        for (const int nei: adj[i]) {
            if (nei == p) continue;
            if (!this->helper(adj, vst, i, nei)) {
                return false;
            }
        }

        return true;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        vector<bool> vst(n, false);
        for (const auto& ei: edges) {
            adj[ei[0]].push_back(ei[1]);
            adj[ei[1]].push_back(ei[0]);
        }
        
        if (!this->helper(adj, vst, -1, 0)) {
            return false;
        }

        for (int i = 0; i < n; ++i) {
            if (!vst[i]) return false;
        }

        return true;
    }
};
