#include <vector>

using namespace std;

class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int tar) {
    int adj = 20000;
    vector<int> prev(40001, 0), curr(40001, 0);

    prev[-nums[0] + adj] += 1;
    prev[nums[0] + adj] += 1;

    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < curr.size(); ++j) {
        if (prev[j]) {
          if (j + nums[i] < curr.size()) {
            curr[j + nums[i]] += prev[j];
          }

          if (j - nums[i] >= 0) {
            curr[j - nums[i]] += prev[j];
          }
        }
      }

      prev = curr;
      fill(curr.begin(), curr.end(), 0);
    }

    return prev[tar + adj];
  }
};
