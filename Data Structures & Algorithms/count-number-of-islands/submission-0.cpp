class Solution {
private:
void dfs(auto& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '*' || grid[i][j] == '0') {
        return;
    }

    grid[i][j] = '*';
    dfs(grid, i+1, j);
    dfs(grid, i-1, j);
    dfs(grid, i, j+1);
    dfs(grid, i, j-1);
}
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int I = grid.size(), J = grid[0].size();
        for (int i = 0; i < I; ++i) {
            for (int j = 0; j < J; ++j) {
                if (grid[i][j] == '0' || grid[i][j] == '*') continue;
                res++;
                dfs(grid, i, j);
            }   
        }
        return res;
    }
};
