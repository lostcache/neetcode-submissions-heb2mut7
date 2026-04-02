class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.length() == 0) return 0;

        int l = 0, maxF = 0, res = 0;
        map<char, int> seen;
        for (int r = 0; r < s.length(); ++r) {
            seen[s[r]]++;
            maxF = max(maxF, seen[s[r]]);

            while ((r - l + 1) - maxF > k) {
                seen[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};
