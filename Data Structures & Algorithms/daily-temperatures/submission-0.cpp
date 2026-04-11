class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<pair<int, int>> st;
        vector<int> res(temp.size(), 0);

        for (int i = 0; i < temp.size(); ++i) {
            if (st.empty() || st.back().first >= temp[i]) {
                st.push_back({temp[i], i});
            } else {
                while (!st.empty() && st.back().first < temp[i]) {
                    auto [_, prevIdx] = st.back();
                    st.pop_back();

                    res[prevIdx] = i - prevIdx;
                }

                st.push_back({temp[i], i});
            }
        }

        return res;
    }
};
