class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->preSum = matrix;

        for (int j = 1; j < matrix[0].size(); ++j) {
            this->preSum[0][j] += this->preSum[0][j - 1];
        }
        for (int i = 1; i < matrix.size(); ++i) {
            this->preSum[i][0] += this->preSum[i - 1][0];
        }
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                this->preSum[i][j] += (this->preSum[i - 1][j] + this->preSum[i][j - 1] - this->preSum[i- 1][j - 1]);
            }
        }
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
            }
        }
    }   
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = this->preSum[row2][col2];
        if (row1 == 0 && col1 == 0) return total;

        total -= this->preSum[row2][col1 - 1];
        if (row1 == 0) return total;

        total -= this->preSum[row1 - 1][col2];
        if (col1 == 0) return total;

        total += this->preSum[row1 - 1][col1 - 1];
        return total;
    }
    
private:
    vector<vector<int>> preSum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */