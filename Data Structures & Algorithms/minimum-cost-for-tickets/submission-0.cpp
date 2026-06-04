#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    map<pair<int, int>, int> memo;
    auto dfs = [&](auto &&self, int valid_till, int idx) -> int {
      if (idx >= days.size()) {
        return 0;
      }

      if (memo.find({idx, valid_till}) != memo.end()) {
        return memo[{idx, valid_till}];
      }

      if (valid_till >= days[idx]) {
        memo[{idx, valid_till}] = self(self, valid_till, idx + 1);
      } else {
        int one_day = costs[0] + self(self, days[idx] + 0, idx);
        int seven_days = costs[1] + self(self, days[idx] + 6, idx);
        int thirty_days = costs[2] + self(self, days[idx] + 29, idx);
        memo[{idx, valid_till}] = min({one_day, seven_days, thirty_days});
      }

      return memo[{idx, valid_till}];
    };

    return dfs(dfs, 0, 0);
  }
};