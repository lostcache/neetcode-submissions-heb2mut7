#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  vector<string> res;
  map<char, vector<char>> m;
  string st;

  void dfs(const string &s, int idx) {
    if (idx >= s.length()) {
      this->res.push_back(this->st);
      return;
    }

    for (char c : this->m[s[idx]]) {
      this->st.push_back(c);
      this->dfs(s, idx + 1);
      this->st.pop_back();
    }
  }

public:
  Solution() {
    this->m['2'] = {'a', 'b', 'c'};
    this->m['3'] = {'d', 'e', 'f'};
    this->m['4'] = {'g', 'h', 'i'};
    this->m['5'] = {'j', 'k', 'l'};
    this->m['6'] = {'m', 'n', 'o'};
    this->m['7'] = {'p', 'q', 'r', 's'};
    this->m['8'] = {'t', 'u', 'v'};
    this->m['9'] = {'w', 'x', 'y', 'z'};
  }

  vector<string> letterCombinations(string digits) {
    if (!digits.length())
      return {};

    this->res.clear();
    this->dfs(digits, 0);
    return this->res;
  }
};