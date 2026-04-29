#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int jump(vector<int> &nums) {
    if (nums.size() == 1)
      return 0;

    int currIdx = 0;
    int jumps = 0;
    while (true) {
      if (nums[currIdx] + currIdx >= nums.size() - 1)
        return jumps + 1;

      int bestRangeIdx = -1;
      int currBestRange = INT_MIN;
      // for every possible jump
      for (int j = currIdx + 1;
           j <= min(currIdx + nums[currIdx], (int)nums.size()); ++j) {

        // record the one with max next range
        if (nums[j] + j > currBestRange) {
          currBestRange = nums[j] + j;
          bestRangeIdx = j;
        }
      }

      // cout << currIdx << " -> " << bestRangeIdx << endl;
      currIdx = bestRangeIdx;
      jumps++;
    }

    return jumps;
  }
};