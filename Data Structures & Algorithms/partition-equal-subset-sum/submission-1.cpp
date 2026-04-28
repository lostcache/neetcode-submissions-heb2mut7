#include <iostream>
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
      auto temp = dp;
      for (int j = 0; j < dp.size(); ++j) {
        if (dp[j] && j + nums[i] < dp.size()) {
          temp[j + nums[i]] = true;
        }
      }
      dp = temp;
    }

    return dp[tar];
  }
};