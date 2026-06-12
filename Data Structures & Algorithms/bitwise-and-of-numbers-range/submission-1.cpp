#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

class Solution {
public:
  int rangeBitwiseAnd(int left, int right) {
    uint64_t res = (((uint64_t)1 << 31) - 1) | ((uint64_t)1 << 31);
    for (uint64_t i = 0; i < 32; ++i) {
      uint64_t n = ((uint64_t)1 << i);
      uint64_t zero_mask = ~((uint64_t)1 << i);
      if (right < n) {
        res &= zero_mask;
      }
      if (right - left + 1 > n) {
        res &= zero_mask;
      } else {
        if (!(left & ((uint64_t)1 << i) && (right & ((uint64_t)1 << i)))) {
          res &= zero_mask;
        }
      }
    }
    return res;
  }
};