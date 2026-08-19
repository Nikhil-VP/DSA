class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        
        // Optimize k if it exceeds total grid size
        k = k % total;
        if (k == 0) return grid;

        vector<vector<int>> result(m, vector<int>(n));

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                // Find 1D index and shift it by k
                int old_index = r * n + c;
                int new_index = (old_index + k) % total;

                // Convert back to 2D coordinates
                int new_r = new_index / n;
                int new_c = new_index % n;

                result[new_r][new_c] = grid[r][c];
            }
        }

        return result;
    }
};