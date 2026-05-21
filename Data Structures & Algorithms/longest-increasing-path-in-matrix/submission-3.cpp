#include <vector>

using namespace std;

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int ans = 1;
    vector<vector<int>> vst(matrix.size(), vector<int>(matrix[0].size(), 1));

    while (true) {
      bool expanded = false;
      for (int i = 0; i < vst.size(); ++i) {
        for (int j = 0; j < vst[0].size(); ++j) {
          for (auto [di, dj] : dirs) {
            int pi = i + di, pj = j + dj;
            if (pi < 0 || pi >= matrix.size() || pj < 0 ||
                pj >= matrix[0].size() || matrix[i][j] <= matrix[pi][pj]) {
              continue;
            }
            if (vst[pi][pj] + 1 > vst[i][j]) {
              vst[i][j] = vst[pi][pj] + 1;
              expanded = true;
              ans = max(ans, vst[i][j]);
            }
          }
        }
      }

      if (!expanded) {
        break;
      }
    }

    return ans;
  }
};