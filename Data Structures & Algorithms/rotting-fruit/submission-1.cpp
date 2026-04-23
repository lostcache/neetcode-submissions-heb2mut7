#include <queue>
#include <stdint.h>
#include <vector>

using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    int res = 0;
    queue<Coord> q;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        // add to queue if spoiled
        if (grid[i][j] == 2)
          q.push({i, j});
      }
    }

    while (!q.empty()) {
      int cnt = q.size();
      // spread to all nei in a second
      for (int i = 0; i < cnt; ++i) {
        auto [cr, cc] = q.front();
        q.pop();
        for (auto [dr, dc] : dirs) {
          int nr = cr + dr, nc = cc + dc;
          if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() &&
              grid[nr][nc] == 1) {
            // if within limits of grid and not spoiled
            grid[nr][nc] = 2; // spoil
            q.push({nr, nc}); // will spoil others
          }
        }
      }

      // tick the seconds, if spoiled some, else already done at this moment.
      if (q.size())
        res++;
    }

    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        // cannot spoil all, one/more are unreachable
        if (grid[i][j] == 1)
          return -1;
      }
    }

    // res is the current second, all were spoiled in prev second.
    return res;
  }

private:
  int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  struct Coord {
    int r;
    int c;
  };
};