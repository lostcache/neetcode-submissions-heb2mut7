#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int change(int amount, vector<int> &coins) {
    return this->dfs(coins, 0, 0, amount);
  }

private:
  map<pair<int, int>, int> cache;
  int dfs(const vector<int> &coins, int idx, int sum, int target) {
    if (sum == target) {
      this->cache[{idx, sum}] = 1;
      return this->cache[{idx, sum}];
    }

    if (this->cache.find({idx, sum}) != this->cache.end()) {
      return this->cache[{idx, sum}];
    }

    int use = 0;
    if (sum + coins[idx] <= target) {
      use = this->dfs(coins, idx, sum + coins[idx], target);
    }

    int dont_use = 0;
    if (idx + 1 < coins.size()) {
      dont_use = this->dfs(coins, idx + 1, sum, target);
    }

    this->cache[{idx, sum}] = use + dont_use;
    return this->cache[{idx, sum}];
  }
};
