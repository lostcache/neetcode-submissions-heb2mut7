class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        map<char, int> m1, m2;
        for (const char c: s1) {
            m1[c]++;
        }
        
        int t = m1.size(), match = 0;
        for (int i = 0; i < s1.size(); ++i) {
            m2[s2[i]]++;
        }

        for (auto const& [key, val] : m1) {
            if (m2[key] == val) match++;
        }

        if (match == t) {
            return true;
        }

        int l = 0;
        for (int i = s1.size(); i < s2.size(); ++i) {
            char leftChar = s2[l];
            if (m1.count(leftChar)) {
                if (m2[leftChar] == m1[leftChar]) match--;
                m2[leftChar]--;
                if (m2[leftChar] == m1[leftChar]) match++;
            } else {
                m2[leftChar]--;
            }
            l++;

            char rightChar = s2[i];
            if (m1.count(rightChar)) {
                if (m2[rightChar] == m1[rightChar]) match--;
                m2[rightChar]++;
                if (m2[rightChar] == m1[rightChar]) match++;
            } else {
                m2[rightChar]++;
            }

            if (match == t) {
                return true;
            }
        }

        return false;
    }
};