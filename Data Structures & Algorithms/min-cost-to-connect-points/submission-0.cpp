class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int N = points.size();
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < N; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < N; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }

        int res = 0;
        unordered_set<int> visit;
        visit.reserve(N);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq{};
        pq.push({0, 0});
        while (visit.size() < N) {
            auto [c, i] = pq.top(); pq.pop();
            if (visit.count(i)) continue;
            res += c;
            visit.insert(i);
            for (const auto& [nc, ni] : adj[i]) {
                if (!visit.count(ni)) {
                    pq.push({nc, ni});
                }
            }
        }
        return res;
    }
};
