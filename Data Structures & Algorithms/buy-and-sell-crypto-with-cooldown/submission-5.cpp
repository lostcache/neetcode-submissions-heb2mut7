#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    vector<int> b(prices.size(), INT_MIN), nb(prices.size(), INT_MIN);
    b[0] = -prices[0];
    nb[0] = 0;

    for (int i = 1; i < prices.size(); ++i) {
      // if bought
      if (b[i - 1] > INT_MIN) {
        // keep it, do nothing
        b[i] = max(b[i], b[i - 1]);
        // sell it
        nb[i] = max(nb[i], b[i - 1] + prices[i]);
      }

      // if not bought
      if (nb[i - 1] > INT_MIN) {
        // do not buy, do nothing
        nb[i] = max(nb[i], nb[i - 1]);
        // buy,
        b[i] = max(b[i], -prices[i]);
        // add prev profits.
        if (i - 2 >= 0) {
          b[i] = max(b[i], nb[i - 2] - prices[i]);
        } else {
          b[i] = max(b[i], -prices[i]);
        }
      }
    }

    // for (int i = 0; i < prices.size(); ++i) {
    //   cout << b[i] << ", ";
    // }
    // cout << endl;

    // for (int i = 0; i < prices.size(); ++i) {
    //   cout << nb[i] << ", ";
    // }
    // cout << endl;

    return max(nb[prices.size() - 1], b[prices.size() - 1]);
  }
};