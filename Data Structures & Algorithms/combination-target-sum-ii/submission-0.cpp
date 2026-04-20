#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> res;
  vector<int> st;
  void dfs(const vector<int> &can, int tar, int idx, int curr_sum) {
    if (idx >= can.size()) {
      if (curr_sum == tar) {
        res.push_back(st);
      }
      return;
    }

    int incl_sum = curr_sum + can[idx];

    // include curr
    this->st.push_back(can[idx]);
    if (incl_sum <= tar) {
      dfs(can, tar, idx + 1, incl_sum);
    }
    this->st.pop_back();

    while (idx + 1 < can.size() && can[idx + 1] == can[idx])
      idx++;

    // exclude
    dfs(can, tar, idx + 1, curr_sum);
  }

public:
  vector<vector<int>> combinationSum2(vector<int> &can, int tar) {
    sort(can.begin(), can.end());
    this->dfs(can, tar, 0, 0);
    return res;
  }
};