#include <climits>
#include <cstdlib>
#include <stdint.h>
#include <vector>

using namespace std;

class Solution {
public:
  int minCostConnectPoints(vector<vector<int>> &p) {
    vector<bool> inMST(1004, false);
    vector<int> minDist(1004, INT_MAX);
    int inGraph = 0;
    int currNode = 0, nextNode = -1, res = 0;

    while (inGraph < p.size() - 1) {
      inMST[currNode] = true;
      inGraph++;

      for (int i = 0; i < p.size(); ++i) {
        if (inMST[i])
          continue;
        int dist =
            abs(p[currNode][0] - p[i][0]) + abs(p[currNode][1] - p[i][1]);
        minDist[i] = min(minDist[i], dist);

        if (nextNode == -1 || minDist[i] < minDist[nextNode]) {
          nextNode = i;
        }
      }

      res += minDist[nextNode];
      currNode = nextNode;
      nextNode = -1;
    }

    return res;
  }
};