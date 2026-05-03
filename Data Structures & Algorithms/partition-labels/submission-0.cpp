#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> partitionLabels(string s) {
    vector<int> lastIndex(26, -1);
    for (int i = 0; i < s.length(); ++i) {
      lastIndex[s[i] - 'a'] = i;
    }

    vector<int> res;
    int lastEndIdx = -1;
    int currEndIdx = -1;
    for (int i = 0; i < s.length(); ++i) {
      currEndIdx = max(currEndIdx, lastIndex[s[i] - 'a']);

      if (currEndIdx == i) {
        res.push_back(i - lastEndIdx);
        lastEndIdx = currEndIdx;
      }
    }

    return res;
  }
};