class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int, int>> posSpeed;
        for (int i = 0; i < n; ++i) {
            posSpeed.push_back({position[i], speed[i]});
        }

        sort(posSpeed.begin(), posSpeed.end());
 
        vector<double> time;
        for (auto [pos, spd]: posSpeed) {
            double ti = ((double)(target - pos)) / (double)spd;
            time.push_back(ti);
        }

        vector<double> st;
        for (auto ti: time) {
            while (!st.empty() && st.back() <= ti) {
                st.pop_back();
            }
            st.push_back(ti);
        }

        return st.size();
    }
};
