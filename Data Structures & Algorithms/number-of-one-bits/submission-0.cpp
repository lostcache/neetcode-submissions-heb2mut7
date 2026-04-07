class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num = n;
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            if (num & (uint32_t)1 << i) res++;
        }
        return res;
    }
};
