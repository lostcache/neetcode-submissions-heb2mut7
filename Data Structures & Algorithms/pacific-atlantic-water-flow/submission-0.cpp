class Solution {
private:
    void dfs(auto& can, int i, int j, int hei, const auto& heights) {
        if (i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size() || heights[i][j] < hei) return;
        if (can[i][j]) return;
        can[i][j] = true;
        dfs(can, i+1, j, heights[i][j], heights);
        dfs(can, i-1, j, heights[i][j], heights);
        dfs(can, i, j+1, heights[i][j], heights);
        dfs(can, i, j-1, heights[i][j], heights);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int I = heights.size(), J = heights[0].size();
        auto canP = vector<vector<bool>>(I, vector<bool>(J, false));
        auto canA = vector<vector<bool>>(I, vector<bool>(J, false));
        for (int i = 0; i < I; ++i) {
            dfs(canP, i, 0, -INT_MAX, heights);
        }
        for (int j = 0; j < J; ++j) {
            dfs(canP, 0, j, -INT_MAX, heights);
        }
        for (int i = 0; i < I; ++i) {
            dfs(canA, i, J - 1, -INT_MAX, heights);
        }
        for (int j = 0; j < J; ++j) {
            dfs(canA, I - 1, j, -INT_MAX, heights);
        }

        vector<vector<int>> res;

        for (int i = 0; i < I; ++i) {
            for (int j = 0; j < J; ++j) {
                if (canP[i][j] && canA[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
