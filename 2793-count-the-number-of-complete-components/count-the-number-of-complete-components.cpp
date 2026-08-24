#include <vector>

class Solution {
public:
    int countCompleteComponents(int n, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        std::vector<bool> visited(n, false);
        int completeCount = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;

            // Collect all nodes in the current connected component
            std::vector<int> component;
            dfs(i, adj, visited, component);

            // Check if every node in the component has a degree equal to component.size() - 1
            bool isComplete = true;
            int componentSize = component.size();
            for (int node : component) {
                if (adj[node].size() != componentSize - 1) {
                    isComplete = false;
                    break;
                }
            }

            if (isComplete) {
                completeCount++;
            }
        }

        return completeCount;
    }

private:
    void dfs(int node, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited, std::vector<int>& component) {
        visited[node] = true;
        component.push_back(node);
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, component);
            }
        }
    }
};