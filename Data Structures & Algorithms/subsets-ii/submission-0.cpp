#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  vector<int> st;
  vector<vector<int>> res;

private:
  void dfs(const vector<int> &n, int idx) {
    if (idx >= n.size()) {
      this->res.push_back(this->st);
      return;
    }

    this->st.push_back(n[idx]);
    this->dfs(n, idx + 1);
    this->st.pop_back();

    while (idx + 1 < n.size() && n[idx] == n[idx + 1])
      idx++;
    this->dfs(n, idx + 1);
  }

public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    this->dfs(nums, 0);
    return this->res;
  }
};