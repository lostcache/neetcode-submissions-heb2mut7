class Solution {
private:
    vector<vector<int>> res;
    vector<int> st;

    void dfs(const auto& v, int idx) {
        if (idx == v.size()) {
            res.push_back(st);
            return;
        }

        // exclude
        this->dfs(v, idx + 1);

        // include
        st.push_back(v[idx]);
        this->dfs(v, idx + 1);
        st.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        this->dfs(nums, 0);
        return this->res;
    }
};