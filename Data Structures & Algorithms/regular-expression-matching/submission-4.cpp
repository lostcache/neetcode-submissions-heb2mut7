#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    // map<pair<int, int>, bool> memo;
    // auto dfs = [&](auto &&self, int si, int pi) -> bool {
    //   if (memo.find({si, pi}) != memo.end()) {
    //     return memo[{si, pi}];
    //   }

    //   if (pi >= p.length()) {
    //     return si >= s.length();
    //   }

    //   memo[{si, pi}] = si < s.length() && (p[pi] == s[si] || p[pi] == '.');

    //   if (pi + 1 < p.length() && p[pi + 1] == '*') {
    //     memo[{si, pi}] = (self(self, si, pi + 2) ||
    //                       (memo[{si, pi}] && self(self, si + 1, pi)));
    //   } else {
    //     memo[{si, pi}] &= self(self, si + 1, pi + 1);
    //   }

    //   return memo[{si, pi}];
    // };

    // return dfs(dfs, 0, 0);

    vector<vector<int>> dp(p.length() + 1, vector<int>(s.length() + 1, false));
    dp[0][0] = true;
    for (int pi = 1; pi <= p.length(); ++pi) {
      dp[pi][0] = false;
    }

    for (int pi = 2; pi <= p.length(); ++pi) {
      if (p[pi - 1] == '*') {
        dp[pi][0] = dp[pi - 2][0];
      }
    }

    for (int si = 1; si <= s.length(); ++si) {
      dp[0][si] = false;
    }

    for (int pi = 1; pi <= p.length(); ++pi) {
      for (int si = 1; si <= s.length(); ++si) {
        if (p[pi - 1] == '*') {
          dp[pi][si] = dp[pi - 2][si];
          if (p[pi - 2] == s[si - 1] || p[pi - 2] == '.') {
            dp[pi][si] |= dp[pi][si - 1];
          }
        } else {
          dp[pi][si] = dp[pi - 1][si - 1] &&
                       (p[pi - 1] == s[si - 1] || p[pi - 1] == '.');
        }
      }
    }

    return dp[p.length()][s.length()];
  }
};