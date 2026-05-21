#include <climits>
#include <iostream>
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
          this->dfs(matrix, vst, 1, i, j);
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
  void dfs(const vector<vector<int>> &mat, vector<vector<int>> &vst, int ele,
           int i, int j) {
    vst[i][j] = ele;
    for (auto [di, dj] : this->dirs) {
      int ni = i + di, nj = j + dj;
      if (ni < 0 || ni >= vst.size() || nj < 0 || nj >= vst[0].size() ||
          mat[ni][nj] <= mat[i][j] || vst[ni][nj] >= ele + 1) {
        continue;
      }
      this->dfs(mat, vst, ele + 1, ni, nj);
    }
  }
};