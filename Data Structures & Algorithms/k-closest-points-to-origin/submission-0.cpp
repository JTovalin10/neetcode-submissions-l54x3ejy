class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // max heap so we only keep the k closest
        // dist, (x, y)
        priority_queue<pair<int, vector<int>>> pq{};
        for (const auto& point : points) {
            int x = point[0];
            int y = point[1];
            int dst = pow(x, 2) + pow(y, 2);
            pq.push({dst, {x, y}});
            if (pq.size() > k) pq.pop();
        }

        vector<vector<int>> res{};
        res.reserve(k);
        while (!pq.empty()) {
            auto vec = pq.top().second; pq.pop();
            int x = vec[0];
            int y = vec[1];
            res.push_back({x, y});
        }
        return res;
    }
};
