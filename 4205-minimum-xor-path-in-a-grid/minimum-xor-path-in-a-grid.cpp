// class Solution {
// public:
//     int minCost(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         for(int i=1;i<n;i++){
//             grid[0][i]=grid[0][i] ^ grid[0][i-1];
//         }
//         for(int i=1;i<m;i++){
//             grid[i][0]=grid[i][0] ^ grid[i-1][0];
//         }
//         for(int i=1;i<m;i++){
//             for(int j=1;j<n;j++){
//                 grid[i][j]=min(grid[i][j-1]^grid[i][j],grid[i-1][j]^grid[i][j]);
//             }
//         }
//         return grid[m-1][n-1];
//     }
// };
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<unordered_set<int>>> dp(
            m, vector<unordered_set<int>>(n)
        );

        dp[0][0].insert(grid[0][0]);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;

                if (i > 0) {
                    for (int x : dp[i - 1][j]) {
                        dp[i][j].insert(x ^ grid[i][j]);
                    }
                }

                if (j > 0) {
                    for (int x : dp[i][j - 1]) {
                        dp[i][j].insert(x ^ grid[i][j]);
                    }
                }
            }
        }

        return *min_element(
            dp[m - 1][n - 1].begin(),
            dp[m - 1][n - 1].end()
        );
    }
};