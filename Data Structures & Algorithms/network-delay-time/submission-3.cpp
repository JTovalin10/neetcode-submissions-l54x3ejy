class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> edges{};
        edges.reserve(n);
        for (const auto& time : times) {
            edges[time[0]].emplace_back(time[2], time[1]);
        }
        priority_queue<pair<int,  int>, vector<pair<int, int>>, greater<>> pq{};
        unordered_set<int> visited{};
        visited.reserve(n);
        pq.push({0, k});
        int t = 0;
        while (!pq.empty()) {
            auto [w1, n1] = pq.top(); pq.pop();
            if (visited.contains(n1)) continue;
            visited.insert(n1); // add to visitd set
            t = w1;
            for (const auto& [w2, n2] : edges[n1]) {
                // avoid logn operation
                if (!visited.count(n2)) {
                    pq.push({w1 + w2, n2});
                }
            }
        }
        return visited.size() == n ? t : -1;
    }
};
