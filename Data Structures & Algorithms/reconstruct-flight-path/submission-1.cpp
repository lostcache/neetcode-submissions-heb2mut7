#include <algorithm>
#include <iostream>
#include <map>
#include <stdint.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> findItinerary(vector<vector<string>> &tickets) {
    for (int i = 0; i < tickets.size(); ++i) {
      string from = tickets[i][0], to = tickets[i][1];
      adj[from].push_back(to);
      pair<string, string> key = {from, to};
      this->routeCounter[key] += 1;
    }

    for (auto &[from, tos] : this->adj) {
      sort(tos.begin(), tos.end());
    }

    // for (const string &to : this->adj["JFK"]) {
    //   cout << to << ", ";
    // }
    // cout << endl;

    this->dfs("JFK");

    reverse(this->res.begin(), this->res.end());
    return this->res;
  }

private:
  map<string, vector<string>> adj;
  vector<string> res;
  map<pair<string, string>, int> routeCounter;

  void dfs(string from) {
    for (const string &to : this->adj[from]) {
      pair<string, string> key = {from, to};
      if (!this->routeCounter[key])
        continue;
      this->routeCounter[key] -= 1;
      // cout << from << " -> " << to << endl;
      this->dfs(to);
    }
    this->res.push_back(from);
  }
};