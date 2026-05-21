#include <vector>

using namespace std;

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    int ans = -1;
    vector<vector<int>> vst(matrix.size(), vector<int>(matrix[0].size(), -1));
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[0].size(); ++j) {
        if (vst[i][j] == -1) {
          this->dfs(matrix, vst, i, j);
        }
      }
    }

    for (int i = 0; i < vst.size(); ++i) {
      for (int j = 0; j < vst[0].size(); ++j) {
        ans = max(ans, vst[i][j]);
      }
    }

    return ans;
  }

private:
  int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int dfs(const vector<vector<int>> &mat, vector<vector<int>> &vst, int i,
          int j) {
    if (vst[i][j] != -1) {
      return vst[i][j];
    }

    vst[i][j] = 1;
    for (auto [di, dj] : this->dirs) {
      int ni = i + di, nj = j + dj;
      if (ni < 0 || ni >= vst.size() || nj < 0 || nj >= vst[0].size() ||
          mat[ni][nj] <= mat[i][j]) {
        continue;
      }
      vst[i][j] = max(vst[i][j], 1 + this->dfs(mat, vst, ni, nj));
    }

    return vst[i][j];
  }
};