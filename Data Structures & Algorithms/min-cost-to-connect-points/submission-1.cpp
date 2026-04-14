class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int N = points.size();
        unordered_map<int, vector<pair<int, int>>> adj{};
        adj.reserve(N);
        for (int i{0}; i < N; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j{0}; j < N; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq{};
        // weight, node
        pq.push({0, 0});
        int res = 0;
        unordered_set<int> seen{};
        seen.reserve(N);
        while (!pq.empty()) {
            auto [wei, i] = pq.top(); pq.pop();
            if (seen.contains(i)) continue;
            seen.insert(i);
            res += wei;
            for (const auto& [nwei, ni] : adj[i]) {
                if (!seen.contains(ni)) {
                    pq.push({nwei, ni});
                }
            }
        }
        return seen.size() == N ? res : -1;
    }
};
