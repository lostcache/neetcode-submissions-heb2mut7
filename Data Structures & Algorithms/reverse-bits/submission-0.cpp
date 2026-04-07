class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int currBit = (n >> i) & (uint32_t)1;
            res |= (currBit) << (31 - i);
        }
        return res;
    }
};
