#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    vector<vector<int>> adj;
    vector<int> parent_node, depth, heavy, head, pos;
    vector<int> tree_seg;
    string node_str;
    int cur_pos;

    int dfs(int v, int p, int d) {
        depth[v] = d;
        parent_node[v] = p;
        int size = 1, max_c_size = 0;
        for (int u : adj[v]) {
            if (u != p) {
                int c_size = dfs(u, v, d + 1);
                size += c_size;
                if (c_size > max_c_size) {
                    max_c_size = c_size;
                    heavy[v] = u;
                }
            }
        }
        return size;
    }

    void decompose(int v, int h) {
        head[v] = h;
        pos[v] = cur_pos++;
        if (heavy[v] != -1) {
            decompose(heavy[v], h);
        }
        for (int u : adj[v]) {
            if (u != parent_node[v] && u != heavy[v]) {
                decompose(u, u);
            }
        }
    }

    void update_seg(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree_seg[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update_seg(2 * node, l, mid, idx, val);
        else update_seg(2 * node + 1, mid + 1, r, idx, val);
        tree_seg[node] = tree_seg[2 * node] ^ tree_seg[2 * node + 1];
    }

    int query_seg(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree_seg[node];
        int mid = (l + r) / 2;
        return query_seg(2 * node, l, mid, ql, qr) ^ query_seg(2 * node + 1, mid + 1, r, ql, qr);
    }

    int query_path(int u, int v) {
        int res = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) swap(u, v);
            res ^= query_seg(1, 0, n - 1, pos[head[u]], pos[u]);
            u = parent_node[head[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        res ^= query_seg(1, 0, n - 1, pos[u], pos[v]);
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        node_str = s;
        adj.assign(n, vector<int>());
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        parent_node.assign(n, 0);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        cur_pos = 0;

        dfs(0, 0, 0);
        decompose(0, 0);

        tree_seg.assign(4 * n, 0);
        for (int i = 0; i < n; i++) {
            int mask = 1 << (s[i] - 'a');
            update_seg(1, 0, n - 1, pos[i], mask);
        }

        vector<bool> answer;
        for (auto& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                node_str[u] = c;
                int mask = 1 << (c - 'a');
                update_seg(1, 0, n - 1, pos[u], mask);
            } else {
                int u, v;
                ss >> u >> v;
                int path_mask = query_path(u, v);
                // Check if at most one bit is set
                bool is_palindrome = (path_mask & (path_mask - 1)) == 0;
                answer.push_back(is_palindrome);
            }
        }
        return answer;
    }
};