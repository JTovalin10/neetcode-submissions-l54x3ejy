class Solution {
private:
unordered_set<int> visited{};

bool dfs(int node, int parent, const vector<vector<int>>& adj) {
    if (visited.contains(node)) return false;

    visited.insert(node);
    for (int nei : adj[node]) {
        if (nei == parent) continue;
        if (!dfs(nei, node, adj)) return false;
    }
    return true;
}
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) return false;

        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            int src = edge[0];
            int dst = edge[1];
            adj[src].push_back(dst);
            adj[dst].push_back(src);
        }
        visited.reserve(n);
        if (!dfs(0, -1, adj)) return false;
        
        return visited.size() == n;
    }
};
