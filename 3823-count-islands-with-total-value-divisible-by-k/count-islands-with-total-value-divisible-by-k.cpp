class Solution {
public:
    int m, n;
    
    long long dfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return 0;
        }
        if (grid[r][c] == 0 || visited[r][c]) {
            return 0;
        }
        
        visited[r][c] = true;
        long long curr = grid[r][c];
        
        long long left = dfs(grid, visited, r, c - 1);
        long long right = dfs(grid, visited, r, c + 1);
        long long up = dfs(grid, visited, r - 1, c);
        long long down = dfs(grid, visited, r + 1, c);
        
        return curr + left + right + up + down;
    }
    
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    long long totalSum = dfs(grid, visited, i, j);
                    if (totalSum % k == 0) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};