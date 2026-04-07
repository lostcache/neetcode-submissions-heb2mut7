class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // right(0) -> down(1) -> left(2) -> up(3)
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // horizontal(0), vertical(1) to match above
        int steps[2] = {(int)matrix[0].size(), (int)matrix.size() - 1};

        int currDir = 0;
        int currPos[2] = {0, -1};

        vector<int> res;
        while (true) {
            if (steps[currDir % 2] <= 0) return res;
            int dr = dirs[currDir][0], dc = dirs[currDir][1];

            for (int i = 0; i < steps[currDir % 2]; ++i) {
                currPos[0] += dr;
                currPos[1] += dc;
                res.push_back(matrix[currPos[0]][currPos[1]]);
            }

            steps[currDir % 2]--;
            currDir = (currDir + 1) % 4;
        }
        return res;
    }
};
