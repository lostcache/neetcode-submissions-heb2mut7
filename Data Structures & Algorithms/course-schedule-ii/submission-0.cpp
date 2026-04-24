#include <algorithm>
#include <iostream>
#include <queue>
#include <stdint.h>
#include <vector>

using namespace std;

class Solution {
public:
  Solution() {
    adj.resize(1000, vector<int>());
    this->completed.resize(1000, false);
    this->inStack.resize(1000, false);
  }

  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    for (const auto &v : prerequisites) {
      int crs = v[0], pre = v[1];
      this->adj[crs].push_back(pre);
    }

    for (int i = 0; i < numCourses; ++i) {
      if (this->completed[i])
        continue;

      if (!this->dfs(i)) {
        return vector<int>();
      }
      for (int ci : this->st) {
        this->res.push_back(ci);
      }
      this->st.clear();
    }

    return this->res;
  }

private:
  vector<bool> completed, inStack;
  vector<int> res, st;
  vector<vector<int>> adj;

  bool dfs(int crs) {
    if (this->inStack[crs])
      return false;

    if (this->completed[crs])
      return true;

    bool canComplete = true;

    this->inStack[crs] = true;
    for (int pre : this->adj[crs]) {
      canComplete &= this->dfs(pre);
    }
    this->st.push_back(crs);
    this->completed[crs] = true;
    this->inStack[crs] = false;

    return canComplete;
  }
};