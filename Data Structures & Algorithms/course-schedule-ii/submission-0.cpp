class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto& pre : prerequisites) {
            // need to take b first before a
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> res(numCourses);
        int finish = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            res[finish++] = node;
            for (auto& nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) q.push(nei);
            }
        }
        if (finish != numCourses) return {};
        return res;
    }
};
