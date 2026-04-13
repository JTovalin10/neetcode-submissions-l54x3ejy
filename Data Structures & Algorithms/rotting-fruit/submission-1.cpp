class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // bfs approach as we need to do it layer by layer to handle concurrent rotting
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                if (grid[i][j] == 1) fresh++;
            }
        }
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int time = 0;
        while (!q.empty() && fresh > 0) {
            time++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front(); q.pop();
                for (auto [x2, y2] : dir) {
                    int dx = x + x2;
                    int dy = y + y2;
                    if (dx < 0 || dy < 0 || dx >= ROWS || dy >= COLS) continue;
                    if (grid[dx][dy] != 1) continue;
                    grid[dx][dy] = 2; // make it rotten
                    q.push({dx, dy});
                    fresh--;
                }
            }
        }
        return fresh == 0 ? time : -1;
    }
};
