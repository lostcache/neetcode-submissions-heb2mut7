class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        map<char, int> cnt1, cnt2;
        for (auto c: s) {
            cnt1[c]++;
        }
        for (auto c: t) {
            cnt2[c]++;
        }
        for (auto [c, cnt]: cnt1) {
            if (cnt1[c] != cnt2[c]) return false;
        }
        return true;
    }
};
