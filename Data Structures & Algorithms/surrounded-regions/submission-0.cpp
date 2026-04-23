#include <iostream>
#include <queue>
#include <stdint.h>
#include <vector>

using namespace std;

class Solution {
public:
  void solve(vector<vector<char>> &b) {
    // first row
    for (int c = 0; c < b[0].size(); ++c) {
      cout << b[0][c] << endl;
      if (b[0][c] == 'O') {
        this->bfs(b, 0, c);
      }
    }

    // last row
    for (int c = 0; c < b[0].size(); ++c) {
      cout << b[b.size() - 1][c] << endl;
      if (b[b.size() - 1][c] == 'O')
        this->bfs(b, b.size() - 1, c);
    }

    // first col
    for (int r = 0; r < b.size(); ++r) {
      cout << b[r][0] << endl;
      if (b[r][0] == 'O')
        this->bfs(b, r, 0);
    }

    // last col
    for (int r = 0; r < b.size(); ++r) {
      cout << b[r][b[0].size() - 1] << endl;
      if (b[r][b[0].size() - 1] == 'O')
        this->bfs(b, r, b[0].size() - 1);
    }

    for (int i = 0; i < b.size(); ++i) {
      for (int j = 0; j < b[0].size(); ++j) {
        b[i][j] = b[i][j] == 'o' ? 'O' : 'X';
      }
    }
  }

private:
  int dirs[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
  struct Coords {
    int i;
    int j;
  };
  void bfs(vector<vector<char>> &b, int i, int j) {
    cout << "inside" << endl;
    queue<Coords> q;
    b[i][j] = 'o';
    q.push({i, j});

    while (!q.empty()) {
      auto [ci, cj] = q.front();
      q.pop();

      for (auto [di, dj] : dirs) {
        int ni = ci + di, nj = cj + dj;
        if (ni >= 0 && ni < b.size() && nj >= 0 && nj < b[0].size() &&
            b[ni][nj] == 'O') {
          b[ni][nj] = 'o';
          q.push({ni, nj});
        }
      }
    }
  };
};