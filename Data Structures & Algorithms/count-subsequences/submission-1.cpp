#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int numDistinct(string s, string t) {
    if (t.length() > s.length())
      return 0;

    vector<vector<int>> dp(t.size() + 1, vector<int>(s.size() + 1, 0));

    for (int si = 0; si <= s.length(); ++si) {
      dp[0][si] = 1;
    }

    for (int ti = 1; ti <= t.length(); ++ti) {
      for (int si = 1; si <= s.length(); ++si) {
        dp[ti][si] += dp[ti][si - 1];
        if (t[ti - 1] == s[si - 1]) {
          dp[ti][si] += dp[ti - 1][si - 1];
        }
      }
    }

    return dp[t.length()][s.length()];
  }
};