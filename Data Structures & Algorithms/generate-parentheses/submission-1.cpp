#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  vector<string> res;
  string st;
  void dfs(int open, int close, const int n) {
    if (this->st.length() >= (2 * n)) {
      this->res.push_back(this->st);
      return;
    }

    if (open < n) {
      // open new
      st.push_back('(');
      this->dfs(open + 1, close, n);
      st.pop_back();
    }

    // close
    if (close < open) {
      st.push_back(')');
      this->dfs(open, close + 1, n);
      st.pop_back();
    }
  }

public:
  vector<string> generateParenthesis(int n) {
    this->st = "(";
    this->dfs(1, 0, n);
    return this->res;
  }
};