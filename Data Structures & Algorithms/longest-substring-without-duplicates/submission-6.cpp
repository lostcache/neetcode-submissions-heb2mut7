class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int, int> last_seen;
        int max_len = 0, win_start = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (last_seen.find(s[i]) != last_seen.end()) {
                win_start = max(last_seen[s[i]] + 1, win_start);
            }
            last_seen[s[i]] = i;
            max_len = max(max_len, i - win_start + 1);
        }
        return max_len;
    }
};
