#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) {
      return false;
    }

    string st;
    return this->dfs(s1, s2, s3, st, 0, 0);
  }

private:
  map<pair<int, int>, bool> cache;
  bool dfs(const string &s1, const string &s2, const string &s3, string &st,
           int s1i, int s2i) {
    if (st.size() > s3.size()) {
      return false;
    }

    if (st.size() == s3.size()) {
      return true;
    }

    if (this->cache.find({s1i, s2i}) != this->cache.end()) {
      return this->cache[{s1i, s2i}];
    }

    bool can = false;

    if (s1i < s1.size() && s1[s1i] == s3[st.size()]) {
      st.push_back(s1[s1i]);
      can = can || this->dfs(s1, s2, s3, st, s1i + 1, s2i);
      st.pop_back();
    }

    if (s2i < s2.size() && s2[s2i] == s3[st.size()]) {
      st.push_back(s2[s2i]);
      can = can || this->dfs(s1, s2, s3, st, s1i, s2i + 1);
      st.pop_back();
    }

    this->cache[{s1i, s2i}] = can;
    return this->cache[{s1i, s2i}];
  }
};
