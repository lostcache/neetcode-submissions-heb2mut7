#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
  int diags[4][2] = {{+1, -1}, {+1, +1}, {-1, +1}, {-1, -1}};
  vector<vector<string>> res;
  vector<string> state;
  unordered_set<int> atk_row, atk_col, atk_pdiag, atk_ndiag;

  bool isAtk(int r, int c) {
    return (this->atk_row.count(r) || this->atk_col.count(c) ||
            this->atk_ndiag.count(r - c) || this->atk_pdiag.count(r + c));
  }

  void addVst(int r, int c) {
    this->atk_row.insert(r);
    this->atk_col.insert(c);
    this->atk_pdiag.insert(r + c);
    this->atk_ndiag.insert(r - c);
  }

  void rmVst(int r, int c) {
    this->atk_row.erase(r);
    this->atk_col.erase(c);
    this->atk_pdiag.erase(r + c);
    this->atk_ndiag.erase(r - c);
  }

  void dfs(int n, int cr, int cc, int q_cnt) {
    if (q_cnt >= n) {
      this->res.push_back(this->state);
      return;
    }

    if (cr >= n || cc >= n)
      return;

    for (int ri = cr; ri < n; ++ri) {
      for (int ci = cc; ci < n; ++ci) {
        if (this->state[ri][ci] == 'Q' || this->isAtk(ri, ci))
          continue;
        this->state[ri][ci] = 'Q';
        this->addVst(ri, ci);
        this->dfs(n, ri + 1, 0, q_cnt + 1);
        this->rmVst(ri, ci);
        this->state[ri][ci] = '.';
      }
    }
  }

public:
  vector<vector<string>> solveNQueens(int n) {
    this->state = vector<string>(n, string(n, '.'));
    this->res.clear();
    this->dfs(n, 0, 0, 0);
    return this->res;
  }
};