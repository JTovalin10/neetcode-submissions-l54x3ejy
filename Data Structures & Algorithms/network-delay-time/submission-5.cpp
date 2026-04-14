class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj{};
        adj.reserve(n + 1);
        for (const auto& time : times) {
            int u = time[0];
            int v = time[1];
            int t = time[2];
            adj[u].push_back({v, t});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq{};
        pq.push({0, k});
        unordered_set<int> seen{};
        seen.reserve(n + 1);
        int res{};
        while (!pq.empty()) {
            auto [t, node] = pq.top(); pq.pop();
            if (seen.contains(node)) continue;
            seen.insert(node);
            res = t;
            for (const auto& [v, ti] : adj[node]) {
                if (!seen.contains(v)) {
                    pq.push({ti + t, v});
                }
            }
        }
        return seen.size() == n ? res : -1;
    }
};
