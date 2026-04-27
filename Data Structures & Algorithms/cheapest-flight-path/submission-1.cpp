#include <climits>
#include <stdint.h>
#include <vector>

using namespace std;

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    vector<int> minCost = vector<int>(104, INT_MAX);
    minCost[src] = 0;

    for (int i = 0; i <= k; ++i) {
      auto prevIterCost = minCost;
      for (const auto &f : flights) {
        int from = f[0], to = f[1], cost = f[2];
        if (minCost[from] >= INT_MAX)
          continue;

        int newCost = minCost[from] + cost;
        if (newCost < prevIterCost[to]) {
          prevIterCost[to] = newCost;
        }
      }

      minCost = prevIterCost;
    }

    if (minCost[dst] >= INT_MAX)
      return -1;

    return minCost[dst];
  }
};