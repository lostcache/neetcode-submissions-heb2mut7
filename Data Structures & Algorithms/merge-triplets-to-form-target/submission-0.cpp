#include <vector>

using namespace std;

class Solution {
public:
  bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target) {
    int match = 0;
    for (int i = 0; i < triplets.size(); ++i) {
      if (triplets[i][0] == target[0] && triplets[i][1] <= target[1] &&
          triplets[i][2] <= target[2]) {
        match |= (1 << 0);
      }

      if (triplets[i][1] == target[1] && triplets[i][0] <= target[0] &&
          triplets[i][2] <= target[2]) {
        match |= (1 << 1);
      }

      if (triplets[i][2] == target[2] && triplets[i][0] <= target[0] &&
          triplets[i][1] <= target[1]) {
        match |= (1 << 2);
      }

      if (match == 7)
        return true;
    }

    return false;
  }
};