class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";

        map<char, int> goal, curr;
        for (const char c: t) {
            goal[c]++;
        }

        int l = 0; int res = INT_MAX; int best_l = 0; int want = goal.size(), have = 0;
        for (int r = 0; r < s.length(); ++r) {
            curr[s[r]]++;
            if (curr[s[r]] == goal[s[r]]) {
                have++;
            }

            while (want == have) {
                if ((r - l + 1) < res) {
                    res = r - l + 1;
                    best_l = l;
                }
                curr[s[l]]--;
                if (goal[s[l]] > 0 && curr[s[l]] < goal[s[l]]) {
                    have--;
                }
                l++;               
            }
        }

        if (res == INT_MAX) return "";

        return s.substr(best_l, res);
    }
};
