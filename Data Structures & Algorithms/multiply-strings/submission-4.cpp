#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
      return "0";
    }

    string ns1 = num1, ns2 = num2;
    if (ns2.length() > ns1.length()) {
      swap(ns1, ns2);
    }

    vector<vector<int>> inter_res;
    for (int i = ns2.length() - 1; i >= 0; --i) {
      vector<int> resi;
      for (int _ = 1; _ <= (ns2.length() - 1) - i; ++_) {
        resi.push_back(0);
      }
      int carry = 0;
      for (int j = ns1.length() - 1; j >= 0; --j) {
        int mul = ((ns2[i] - '0') * (ns1[j] - '0')) + carry;
        carry = mul / 10;
        resi.push_back(mul % 10);
      }
      if (carry) {
        resi.push_back(carry);
      }
      inter_res.push_back(resi);
    }

    vector<int> res;
    for (const auto &resi : inter_res) {
      int carry = 0;
      for (int i = 0; i < resi.size(); ++i) {
        int sum = 0;
        if (i >= res.size()) {
          sum = resi[i] + carry;
          res.push_back(sum % 10);
          carry = sum / 10;
        } else {
          sum = res[i] + resi[i] + carry;
          res[i] = sum % 10;
          carry = sum / 10;
        }
      }
      int i = resi.size();
      while (carry) {
        int sum = 0;
        if (i >= res.size()) {
          res.push_back(carry % 10);
          carry = carry / 10;
        } else {
          sum = res[i] + carry;
          res[i] = sum % 10;
          carry = sum / 10;
        }
      }
    }

    string res_str;
    for (int i = res.size() - 1; i >= 0; --i) {
      res_str.push_back(res[i] + '0');
    }

    return res_str;
  }
};