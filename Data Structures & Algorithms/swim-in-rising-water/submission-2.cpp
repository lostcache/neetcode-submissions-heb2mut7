#include <climits>
#include <queue>
#include <stdint.h>
#include <vector>

using namespace std;

class Solution {
public:
  int swimInWater(vector<vector<int>> &grid) {
    vector<vector<int>> cost;
    cost.resize(grid.size(), vector<int>(grid[0].size(), INT_MAX));

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<>>
        pq;

    pq.push({grid[0][0], 0, 0});

    while (!pq.empty()) {
      auto [currCost, x, y] = pq.top();
      pq.pop();

      if (x == (grid.size() - 1) && y == (grid[0].size() - 1)) {
        return currCost;
      }

      for (const auto [dx, dy] : this->dirs) {
        int nx = x + dx, ny = y + dy;
        if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size())
          continue;

        int pathMaxCost = max(grid[nx][ny], currCost);

        if (pathMaxCost < cost[nx][ny]) {
          cost[nx][ny] = pathMaxCost;
          pq.push({pathMaxCost, nx, ny});
        }
      }
    }

    return INT_MAX;
  }

private:
  int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};