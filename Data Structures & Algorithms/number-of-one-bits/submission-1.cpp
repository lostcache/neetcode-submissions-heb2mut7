class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num = n;
        int res = 0;
        while (num) {
            num &= num - 1;
            res++;
        }
        return res;
    }
};
