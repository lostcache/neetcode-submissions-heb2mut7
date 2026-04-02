class Solution {
public:
    string longestPalindrome(string s) {
        int mx = 0, bl = -1;
        for (int i = 0; i < s.length(); ++i) {
            int l = i, r = i;
            while (i >= 0 && r < s.length()) {
                if (s[l] == s[r]) {
                    if ((r - l + 1) > mx) {
                        mx = r - l + 1;
                        bl = l;
                    }
                    l--, r++;
                }
                else break;
            }

            l = i, r = i + 1;
            while (i >= 0 && r < s.length()) {
                if (s[l] == s[r]) {
                    if ((r - l + 1) > mx) {
                        mx = r - l + 1;
                        bl = l;
                    }
                    l--, r++;
                }
                else break;
            }
        }

        return s.substr(bl, mx);
    }
};
