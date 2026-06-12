#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool checkValidString(string s) {
    vector<int> open, star;

    for (int i = 0; i < s.length(); ++i) {
      const char c = s[i];
      if (c == '*') {
        star.push_back(i);
      } else if (c == '(') {
        open.push_back(i);
      } else {
        if (!open.empty()) {
          open.pop_back();
        } else if (!star.empty()) {
          star.pop_back();
        } else {
          return false;
        }
      }
    }

    while (!open.empty()) {
      if (star.empty())
        return false;

      if (star.back() > open.back()) {
        open.pop_back();
        star.pop_back();
      } else {
        return false;
      }
    }

    return true;
  }
};