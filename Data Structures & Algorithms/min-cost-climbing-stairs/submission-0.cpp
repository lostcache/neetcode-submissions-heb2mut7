#include <climits>
#include <stdint.h>
#include <vector>

using namespace std;

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    vector<int> minCost(cost.size() + 1, INT_MAX);
    minCost[0] = 0;
    if (cost.size() > 1)
      minCost[1] = 0;

    for (int i = 0; i < cost.size(); ++i) {
      if (i + 1 <= cost.size())
        minCost[i + 1] = min(minCost[i + 1], minCost[i] + cost[i]);
      if (i + 2 <= cost.size())
        minCost[i + 2] = min(minCost[i + 2], minCost[i] + cost[i]);
    }

    return minCost[minCost.size() - 1];
  }
};