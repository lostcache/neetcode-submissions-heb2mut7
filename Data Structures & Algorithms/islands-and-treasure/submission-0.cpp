#include <queue>
#include <stdint.h>
#include <vector>

using namespace std;

class Solution {
public:
  void islandsAndTreasure(vector<vector<int>> &grid) {
    queue<pair<Coord, int>> q;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (!grid[i][j])
          q.push({{i, j}, 0});
      }
    }

    while (!q.empty()) {
      auto [coord, dist] = q.front();
      q.pop();
      for (const auto [dr, dc] : this->dirs) {
        int nr = coord.r + dr, nc = coord.c + dc;
        if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() &&
            grid[nr][nc] && (dist + 1) <= grid[nr][nc] && grid[nr][nc] != -1) {
          grid[nr][nc] = dist + 1;
          q.push({{nr, nc}, dist + 1});
        }
      }
    }
  }

private:
  const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  struct Coord {
    int r;
    int c;
  };
};