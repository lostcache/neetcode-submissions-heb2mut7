#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int numDistinct(string s, string t) { return this->dfs(s, t, 0, 0); }

private:
  map<pair<int, int>, int> cache;
  int dfs(const string &s, const string &t, int sid, int tid) {
    if (tid >= t.length()) {
      return 1;
    }

    if (sid >= s.length()) {
      return 0;
    }

    if (this->cache.find({sid, tid}) != this->cache.end()) {
      return this->cache[{sid, tid}];
    }

    int inc = 0;
    if (s[sid] == t[tid]) {
      inc = this->dfs(s, t, sid + 1, tid + 1);
    }

    int skip = this->dfs(s, t, sid + 1, tid);

    this->cache[{sid, tid}] = inc + skip;

    return inc + skip;
  }
};