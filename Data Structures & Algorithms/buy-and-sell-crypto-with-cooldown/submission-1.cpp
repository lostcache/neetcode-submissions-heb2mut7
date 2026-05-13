#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) { return this->dfs(prices, 0, 0, false); }

private:
  map<pair<int, bool>, int> cache;
  int dfs(const vector<int> &prices, int idx, int profit, bool bought) {
    if (idx >= prices.size()) {
      return 0;
    }

    if (cache.find({idx, bought}) != cache.end()) {
      return cache[{idx, bought}];
    }

    int donothing = this->dfs(prices, idx + 1, profit, bought);

    if (bought) {
      int sell =
          prices[idx] + this->dfs(prices, idx + 2, profit + prices[idx], false);
      cache[{idx, bought}] = max(sell, donothing);
      return cache[{idx, bought}];
    } else {
      int buy =
          -prices[idx] + this->dfs(prices, idx + 1, profit - prices[idx], true);
      cache[{idx, bought}] = max(buy, donothing);
      return cache[{idx, bought}];
    }
  }
};