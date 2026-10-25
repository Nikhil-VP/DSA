class Solution {
public:
    int m, n;

    bool dfs(vector<vector<int>>& grid, int r, int c) {
        // If it goes out of bounds, this island touches the border (not closed)
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return false;
        }
        // If it's water (1) or already visited, return true (it acts as a boundary)
        if (grid[r][c] == 1) {
            return true;
        }
        
        // Mark current land cell as visited by turning it into water
        grid[r][c] = 1;

        // Explore all 4 directions and ensure ALL of them stay within closed bounds
        bool left = dfs(grid, r, c - 1);
        bool right = dfs(grid, r, c + 1);
        bool up = dfs(grid, r - 1, c);
        bool down = dfs(grid, r + 1, c);

        return left && right && up && down;
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int closedIslands = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Find an unvisited land cell
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j)) {
                        closedIslands++;
                    }
                }
            }
        }
        return closedIslands;
    }
};