class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        for (const char c: s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push_back(c);
            } else {
                if (st.size() == 0) return false;

                if (c == ')' && st.back() != '(') {
                    return false;
                } else if (c == '}' && st.back() != '{') {
                    return false;
                } else if (c == ']' && st.back() != '[') {
                    return false;
                }

                st.pop_back();
            }
        }

        if (st.size() > 0) return false;

        return true;
    }
};
