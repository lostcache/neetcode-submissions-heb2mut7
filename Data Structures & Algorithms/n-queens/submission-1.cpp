#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  int diags[4][2] = {{+1, -1}, {+1, +1}, {-1, +1}, {-1, -1}};
  vector<vector<string>> res;
  vector<string> state;

  bool isAtk(int n, int r, int c) {
    for (int ri = 0; ri < n; ++ri) {
      if (this->state[ri][c] == 'Q')
        return true;
    }
    for (int ci = 0; ci < n; ++ci) {
      if (this->state[r][ci] == 'Q')
        return true;
    }

    for (auto [dr, dc] : diags) {
      int ri = r, ci = c;
      while (ri + dr >= 0 && ri + dr < n && ci + dc >= 0 && ci + dc < n) {
        int nr = ri + dr, nc = ci + dc;
        if (this->state[nr][nc] == 'Q')
          return true;
        ri = nr, ci = nc;
      }
    }

    return false;
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
        if (this->state[ri][ci] == 'Q' || this->isAtk(n, ri, ci))
          continue;
        this->state[ri][ci] = 'Q';
        this->dfs(n, ri + 1, 0, q_cnt + 1);
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