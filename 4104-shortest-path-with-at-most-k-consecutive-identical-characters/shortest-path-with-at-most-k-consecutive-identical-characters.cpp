
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        vector<vector<pair<int,int>>> adj(n);

        // Directed graph
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
        }

        const long long INF = 1e18;

        // dist[node][cnt] = minimum cost to reach node
        // with cnt consecutive identical labels
        vector<vector<long long>> dist(
            n, vector<long long>(k + 1, INF)
        );

        // {cost, node, consecutive count}
        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [cost, u, cnt] = pq.top();
            pq.pop();

            if (cost != dist[u][cnt])
                continue;

            for (auto [v, w] : adj[u]) {

                int newCnt;

                if (labels[u] == labels[v])
                    newCnt = cnt + 1;
                else
                    newCnt = 1;

                // More than k consecutive characters
                // is not allowed
                if (newCnt > k)
                    continue;

                long long newCost = cost + w;

                if (newCost < dist[v][newCnt]) {
                    dist[v][newCnt] = newCost;

                    pq.push({
                        newCost, v, newCnt
                    });
                }
            }
        }

        long long ans = INF;

        // Destination can be reached with different
        // consecutive character counts
        for (int cnt = 1; cnt <= k; cnt++) {
            ans = min(ans, dist[n - 1][cnt]);
        }

        return ans == INF ? -1 : (int)ans;
    }
};
