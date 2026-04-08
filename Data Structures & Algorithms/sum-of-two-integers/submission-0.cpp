class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;
        int carry = 0;
        for (int i = 0; i < 32; ++i) {
            int aBit = (a >> i) & 1;
            int bBit = (b >> i) & 1;
            res |= ((aBit ^ bBit ^ carry) << i);
            carry = (aBit + bBit + carry) >= 2 ? 1 : 0;
        }
        return res;
    }
};
