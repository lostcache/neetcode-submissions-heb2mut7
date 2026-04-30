#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = gas.size();
    int tank = 0, total = 0, startIdx = 0;
    for (int i = 0; i < n; ++i) {
      int diff = gas[i] - cost[i];
      tank += diff;
      total += diff;
      if (tank < 0) {
        startIdx = i + 1;
        tank = 0;
      }
    }

    if (total < 0)
      return -1;
    else
      return startIdx;
  }
};