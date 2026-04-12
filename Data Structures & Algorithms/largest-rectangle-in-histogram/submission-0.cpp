class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int maxArea = INT_MIN;
        vector<int> st;
        int n = h.size();

        for (int i = 0; i < n + 1; ++i) {
            while (st.size() && (i == n || h[i] < h[st.back()] )) {
                int previdx = st.back();
                st.pop_back();

                int width;
                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.back() - 1;
                }
                maxArea = max(maxArea, width * h[previdx]);
            }

            st.push_back(i);
        }

        return maxArea;
    }
};
