class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> q;
        for (int s: stones) {
            q.push(s);
        }

        while (q.size() > 1) {
            int f = q.top(); q.pop();
            int s = q.top(); q.pop();
            if (f == s) continue;
            q.push(f - s);
        }

        if (q.size() > 0) {
            return q.top();
        }

        return 0;
    }
};
