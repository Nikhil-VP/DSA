class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long MOD = 1e9 + 7;

        // Helper to resolve landing cell and chain reflections
        auto resolve = [&](int r, int c, int dir) -> pair<int, int> {
            // dir: 0 = moving right, 1 = moving down
            int ci = r, cj = c;
            while (true) {
                if (ci < 0 || ci >= m || cj < 0 || cj >= n) return {-1, -1};
                if (grid[ci][cj] == 0) return {ci, cj};
                // Hit a mirror cell (grid[ci][cj] == 1)
                if (dir == 0) {
                    // entered while moving right -> turn down
                    ci = ci + 1;
                    cj = cj;
                    dir = 1; // now moving down into the new cell
                } else {
                    // entered while moving down -> turn right
                    ci = ci;
                    cj = cj + 1;
                    dir = 0; // now moving right into the new cell
                }
            }
        };

        vector<vector<array<pair<int, int>, 2>>> go(m, vector<array<pair<int, int>, 2>>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If we make a right move from (i, j) to (i, j+1)
                if (j + 1 < n) {
                    go[i][j][0] = resolve(i, j + 1, 0);
                } else {
                    go[i][j][0] = {-1, -1};
                }
                // If we make a down move from (i, j) to (i+1, j)
                if (i + 1 < m) {
                    go[i][j][1] = resolve(i + 1, j, 1);
                } else {
                    go[i][j][1] = {-1, -1};
                }
            }
        }

        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == 0) continue;
                long long ways = dp[i][j];

                // Move right
                auto [ni_r, nj_r] = go[i][j][0];
                if (ni_r != -1 && nj_r != -1) {
                    dp[ni_r][nj_r] = (dp[ni_r][nj_r] + ways) % MOD;
                }

                // Move down
                auto [ni_d, nj_d] = go[i][j][1];
                if (ni_d != -1 && nj_d != -1) {
                    dp[ni_d][nj_d] = (dp[ni_d][nj_d] + ways) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};