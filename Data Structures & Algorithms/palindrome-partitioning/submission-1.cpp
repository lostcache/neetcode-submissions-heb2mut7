#include <string>
#include <string_view>
#include <vector>

using namespace std;

class Solution {
private:
  vector<string> st;
  vector<vector<string>> res;
  bool isPalin(string_view s) {
    int l = 0, r = s.length() - 1;
    while (l <= r) {
      if (s[l] != s[r])
        return false;
      l++, r--;
    }
    return true;
  }

  void dfs(int start, const string &s) {
    if (start >= s.length()) {
      this->res.push_back(this->st);
      return;
    }

    // for every palindromic substring start at i split at that position and
    // look for more recursively.
    for (int i = 1; (start + i) <= s.length(); ++i) {
      string_view ss(s.data() + start, i);
      if (!this->isPalin(ss))
        continue;

      this->st.push_back(string(ss));
      this->dfs(start + i, s);
      this->st.pop_back();
    }
  }

public:
  vector<vector<string>> partition(string s) {
    this->res.clear();
    this->dfs(0, s);
    return this->res;
  }
};