#include <climits>
#include <queue>
#include <stdint.h>
#include <vector>

using namespace std;

class Solution {
public:
  Solution() {
    this->adj.resize(105, vector<pair<int, int>>());
    this->minTimes.resize(104, INT_MAX);
  }

  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    for (int i = 0; i < times.size(); ++i) {
      int ui = times[i][0], vi = times[i][1], ti = times[i][2];
      this->adj[ui].push_back({vi, ti});
    }

    queue<pair<int, int>> q;
    q.push({k, 0});
    this->minTimes[k] = 0;

    while (!q.empty()) {
      auto [ui, t] = q.front();
      q.pop();

      for (auto [vi, ti] : this->adj[ui]) {
        int tt = t + ti;
        if (tt < this->minTimes[vi]) {
          q.push({vi, tt});
          this->minTimes[vi] = tt;
        }
      }
    }

    int maxOfMinTime = -1;
    for (int i = 1; i <= n; ++i) {
      if (this->minTimes[i] >= INT_MAX)
        return -1;
      maxOfMinTime = max(maxOfMinTime, this->minTimes[i]);
    }

    return maxOfMinTime;
  }

private:
  vector<int> minTimes;
  vector<vector<pair<int, int>>> adj;
};