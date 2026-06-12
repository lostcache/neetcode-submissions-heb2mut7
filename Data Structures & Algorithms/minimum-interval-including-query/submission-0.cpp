#include <bits/stdc++.h>
#include <queue>

using namespace std;

class Solution {
public:
  vector<int> minInterval(vector<vector<int>> &intervals,
                          vector<int> &queries) {
    vector<pair<int, int>> sq(queries.size());
    vector<int> res(queries.size(), -1);
    for (int i = 0; i < queries.size(); ++i) {
      sq[i] = {queries[i], i};
    }
    sort(sq.begin(), sq.end());
    sort(intervals.begin(), intervals.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    int i = 0;
    for (const auto [qi, idx] : sq) {
      while (i < intervals.size() && intervals[i][0] <= qi) {
        pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
        i++;
      }

      while (!pq.empty() && pq.top().second < qi) {
        pq.pop();
      }

      if (!pq.empty()) {
        res[idx] = pq.top().first;
      }
    }

    return res;
  }
};