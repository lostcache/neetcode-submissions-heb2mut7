#include <stdint.h>
#include <vector>

using namespace std;

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    long long total = 0;
    for (int i = 0; i < nums.size(); ++i) {
      total += 1LL * nums[i];
    }

    if (total & 1) {
      return false;
    }

    long long tar = total / 2;

    vector<int> dp(5001, false);
    dp[0] = true;

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = tar; j > 0; --j) {
        if (j - nums[i] >= 0 && dp[j - nums[i]]) {
          dp[j] = true;
        }
      }
    }

    return dp[tar];
  }
};