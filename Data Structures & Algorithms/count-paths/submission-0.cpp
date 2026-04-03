class Solution {
private:
    int dfs(int i, int j, int m, int n, auto& cache) {
        if (i > m || j > n) return 0;

        if (i == m && j == n) return 1;

        if (cache.find({i, j}) != cache.end()) {
            return cache[{i, j}];
        }

        int b = dfs(i + 1, j, m, n, cache);
        int r = dfs(i, j + 1, m, n, cache);

        cache[{i, j}] = b + r;

        return cache[{i, j}];
    }
    
public:
    int uniquePaths(int m, int n) {
        map<pair<int, int>, int> cache;
        return this->dfs(1, 1, m, n, cache);
    }
};
