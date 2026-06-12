#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    vector<int> dp(days.size(), INT_MAX - 100000);
    for (int i = 0; i < dp.size(); ++i) {
      if (i > 0) {
        dp[i] = min(dp[i], dp[i - 1] + costs[0]);
      } else {
        dp[i] = min(dp[i], costs[0]);
      }

      int j = i;
      while (j >= 0 && days[i] <= days[j] + 6) {
        j--;
      }
      dp[i] = min(dp[i], (j >= 0 ? dp[j] : 0) + costs[1]);

      j = i;
      while (j >= 0 && days[i] <= days[j] + 29) {
        j--;
      }
      dp[i] = min(dp[i], (j >= 0 ? dp[j] : 0) + costs[2]);
    }

    return dp.back();
  }
};