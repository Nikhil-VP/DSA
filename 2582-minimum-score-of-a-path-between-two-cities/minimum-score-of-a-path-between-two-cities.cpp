class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // Build adjacency list
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& road : roads) {
            int u = road[0], v = road[1], w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int min_score = INT_MAX;
        vector<bool> visited(n + 1, false);
        queue<int> q;

        q.push(1);
        visited[1] = true;

        // BFS to visit all nodes in city 1's connected component
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (const auto& [neighbor, dist] : adj[node]) {
                min_score = min(min_score, dist); // Check all connected edge weights
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return min_score;
    }
};