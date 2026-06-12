#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    map<pair<int, int>, bool> memo;
    auto dfs = [&](auto &&self, int si, int pi) -> bool {
      if (memo.find({si, pi}) != memo.end()) {
        return memo[{si, pi}];
      }

      if (pi >= p.length()) {
        return si >= s.length();
      }

      memo[{si, pi}] = si < s.length() && (p[pi] == s[si] || p[pi] == '.');

      if (pi + 1 < p.length() && p[pi + 1] == '*') {
        memo[{si, pi}] = (self(self, si, pi + 2) ||
                          (memo[{si, pi}] && self(self, si + 1, pi)));
      } else {
        memo[{si, pi}] &= self(self, si + 1, pi + 1);
      }

      return memo[{si, pi}];
    };

    return dfs(dfs, 0, 0);
  }
};