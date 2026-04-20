#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> res;
  unordered_set<int> seen;
  vector<int> st;

  void dfs(const vector<int> &nums) {
    if (this->seen.size() >= nums.size()) {
      this->res.push_back(this->st);
      return;
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (this->seen.find(i) != this->seen.end())
        continue;

      this->st.push_back(nums[i]);
      this->seen.insert(i);
      this->dfs(nums);
      this->seen.erase(i);
      this->st.pop_back();
    }
  }

public:
  vector<vector<int>> permute(vector<int> &nums) {
    this->dfs(nums);
    return this->res;
  }
};