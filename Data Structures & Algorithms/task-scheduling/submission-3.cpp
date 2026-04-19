class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        auto cmp_max = [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp_max)> can_exec(cmp_max);

        // min-heap by eligibility cycle: {eligible_at, char, freq}
        auto cmp_min = [](const tuple<int,char,int>& a, const tuple<int,char,int>& b) {
            return get<0>(a) > get<0>(b);
        };
        priority_queue<tuple<int,char,int>, vector<tuple<int,char,int>>, decltype(cmp_min)> cannot_exec(cmp_min);

        map<char, int> freq;
        for (auto ti : tasks) freq[ti]++;

        for (auto [ti, f] : freq) can_exec.push({ti, f});

        int curr_cycle = 1;
        while (!can_exec.empty() || !cannot_exec.empty()) {
            while (!cannot_exec.empty() && get<0>(cannot_exec.top()) <= curr_cycle) {
                auto [eligible_at, ti, f] = cannot_exec.top();
                cannot_exec.pop();
                can_exec.push({ti, f});
            }

            if (!can_exec.empty()) {
                auto [ti, f] = can_exec.top();
                can_exec.pop();
                if (f - 1) cannot_exec.push({curr_cycle + n + 1, ti, f - 1});
            }
            // else: idle cycle, clock still ticks

            curr_cycle++;
        }

        return curr_cycle - 1;
    }
};