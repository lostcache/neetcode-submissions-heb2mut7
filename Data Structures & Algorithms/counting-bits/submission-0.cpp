class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; ++i) {
            int n = i;
            int resi = 0;
            while (n) {
                n &= n - 1;
                resi++;
            }
            res.push_back(resi);
        }
        return res;
    }
};
