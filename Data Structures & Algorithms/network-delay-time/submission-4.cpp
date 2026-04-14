class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj{};
        adj.reserve(n + 1);
        for (const auto& time : times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq{};
        pq.push({0, k});
        unordered_set<int> seen{};
        seen.reserve(n + 1);
        int res = 0;
        while (!pq.empty()) {
            auto [w, node] = pq.top(); pq.pop();
            if (seen.contains(node)) continue;
            res = w;
            seen.insert(node);
            for (const auto& [dst, ti] : adj[node]) {
                if (!seen.contains(dst)) {
                    pq.push({ti + w, dst});
                }
            } 
        }
        return seen.size() == n  ? res : -1;
    }
};
