class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long min_rate = 1;
        long long max_rate = 0;
        for (int i = 0; i < piles.size(); ++i) {
            max_rate += piles[i];
        }

        long long res_h = max_rate;
        while (min_rate <= max_rate) {
            long long curr_rate = min_rate + (max_rate - min_rate) / 2;
            long long curr_h = 0;
            for (int i = 0; i < piles.size(); ++i) {
                curr_h += (piles[i] + (curr_rate - 1)) / curr_rate;
            }

            if (curr_h > h) {
                min_rate = curr_rate + 1;
            } else {
                max_rate = curr_rate - 1;
                res_h = min(res_h, curr_rate);
            }
        }

        return (int) res_h;
    }
};
