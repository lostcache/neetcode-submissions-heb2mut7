class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;

        for (auto ti: tokens) {
            if (ti == "+" || ti == "-" || ti == "*" || ti == "/") {
                int n2 = st.back();
                st.pop_back();
                int n1 = st.back();
                st.pop_back();
                if (ti == "+") {
                    st.push_back(n1 + n2);
                } else if (ti == "-") {
                    st.push_back(n1 - n2);
                } else if (ti == "*") {
                    st.push_back(n1 * n2);
                } else {
                    st.push_back(n1 / n2);
                }
            } else {
                st.push_back(stoi(ti));
            }
        }

        return st.back();
    }
};
