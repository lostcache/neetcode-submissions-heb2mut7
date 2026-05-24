#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minDistance(string w1, string w2) {
    auto dp = vector<vector<int>>(
        w1.length() + 1, vector<int>(w2.length() + 1, INT_MAX - 10000));

    dp[0][0] = 0;

    for (int i = 1; i <= w1.length(); ++i) {
      dp[i][0] = i;
    }

    for (int j = 1; j <= w2.length(); ++j) {
      dp[0][j] = j;
    }

    for (int i = 1; i <= w1.length(); ++i) {
      for (int j = 1; j <= w2.length(); ++j) {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
        if (w1[i - 1] == w2[j - 1]) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
        } else {
          dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
        }
      }
    }

    return dp[w1.length()][w2.length()];
  }
};