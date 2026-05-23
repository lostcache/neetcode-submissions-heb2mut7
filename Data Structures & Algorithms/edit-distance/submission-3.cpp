#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minDistance(string w1, string w2) {
    if (w1.length() <= w2.length()) {
      return dfs(w1, w2, 0, 0, 0);
    } else {
      return dfs(w2, w1, 0, 0, 0);
    }
  }

private:
  map<pair<int, int>, int> cache;
  int dfs(const string &w1, const string &w2, int i1, int i2, int m) {
    if (i1 >= w1.length())
      return w2.length() - m;

    if (m == w2.length()) {
      return w1.length() - i1;
    }

    if (cache.find({i1, i2}) != cache.end()) {
      return cache[{i1, i2}];
    }

    if (w1[i1] == w2[i2]) {
      cache[{i1, i2}] = dfs(w1, w2, i1 + 1, i2 + 1, m + 1);
    } else {
      int ins = 1 + dfs(w1, w2, i1, i2 + 1, m + 1);
      int del = 1 + dfs(w1, w2, i1 + 1, i2, m);
      int rep = 1 + dfs(w1, w2, i1 + 1, i2 + 1, m + 1);
      cache[{i1, i2}] = min({ins, rep, del});
    }

    return cache[{i1, i2}];
  }
};