class Solution {
private:
    void dfs(const auto& adj, auto& vst, int n) {
        if (vst[n]) return;
        vst[n] = true;
        for (int ni: adj[n]) {
            dfs(adj, vst, ni);
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vst(n + 1, false);
        vector<vector<int>> adj(n + 1, vector<int>());
        for (const auto& n: edges) {
            adj[n[0]].push_back(n[1]);
            adj[n[1]].push_back(n[0]);
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (vst[i]) continue;
            cout << i << endl;
            this->dfs(adj, vst, i);
            res++;
        }

        return res;
    }
};
