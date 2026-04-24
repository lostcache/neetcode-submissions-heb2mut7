#include <stdint.h>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    this->adj.clear();
    this->adj.resize(edges.size() + 1, vector<int>());

    for (const auto &e : edges) {
      this->adj[e[0]].push_back(e[1]);
      this->adj[e[1]].push_back(e[0]);
    }

    this->dfs(1, -1);

    for (int i = edges.size() - 1; i >= 0; --i) {
      int e1 = edges[i][0], e2 = edges[i][1];
      if (this->cycle.find(e1) != this->cycle.end() &&
          this->cycle.find(e2) != this->cycle.end()) {
        return {e1, e2};
      }
    }

    return {-1, -1};
  }

private:
  vector<vector<int>> adj;
  unordered_set<int> vst, cycle;
  int cycleStart = -1;
  bool dfs(int i, int p) {
    if (this->vst.find(i) != this->vst.end()) {
      this->cycleStart = i;
      return true;
    }

    this->vst.insert(i);
    for (int nei : this->adj[i]) {
      if (nei == p)
        continue;

      if (this->dfs(nei, i)) {
        // if cycle detected
        if (this->cycleStart != -1) {
          // if is not the start of the cycle (intersection node).
          this->cycle.insert(i);
        }

        if (cycleStart == i) {
          cycleStart = -1;
        }

        return true;
      }
    }

    return false;
  }
};