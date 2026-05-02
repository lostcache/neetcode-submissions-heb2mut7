#include <vector>

using namespace std;

class Solution {
public:
  bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target) {
    int match = 0;
    for (int i = 0; i < triplets.size(); ++i) {
      int currMatch = 0;
      for (int j = 0; j < 3; ++j) {
        if (triplets[i][j] > target[j]) {
          currMatch = 0;
          break;
        }
        currMatch |= ((triplets[i][j] == target[j]) << j);
      }
      match |= currMatch;

      if (match == 7) {
        return true;
      }
    }

    return false;
  }
};