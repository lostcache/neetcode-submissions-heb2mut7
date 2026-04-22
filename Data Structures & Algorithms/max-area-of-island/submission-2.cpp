#include <stdint.h>
#include <vector>

using namespace std;

class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int res = 0;
    this->vst =
        vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));

    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (vst[i][j] || !grid[i][j])
          continue;

        this->vst[i][j] = true;
        res = max(res, this->dfs(grid, i, j));
      }
    }

    return res;
  }

private:
  vector<vector<bool>> vst;
  int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  int dfs(const vector<vector<int>> &grid, int r, int c) {
    int curr = 1;
    for (auto [dr, dc] : dirs) {
      int nr = r + dr, nc = c + dc;
      if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() &&
          !vst[nr][nc] && grid[nr][nc]) {
        this->vst[nr][nc] = true;
        curr += this->dfs(grid, nr, nc);
      }
    }
    return curr;
  }
};