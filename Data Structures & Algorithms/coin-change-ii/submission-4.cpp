#include <vector>

using namespace std;

class Solution {
public:
  int change(int amount, vector<int> &coins) {
    vector<int> ways(amount + 1, 0);
    ways[0] = 1;

    for (const int ci : coins) {
      for (int i = 1; i < ways.size(); ++i) {
        if (i - ci >= 0) {
          ways[i] += ways[i - ci];
        }
      }
    }

    return ways[amount];
  }
};
