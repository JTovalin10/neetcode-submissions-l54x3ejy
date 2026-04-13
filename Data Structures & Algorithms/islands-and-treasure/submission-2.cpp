#include <array>

class Solution {
private:
int INF = numeric_limits<int>::max();

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // we want the shortest path
        // we can start from each treasure chest and work from there
        int ROWS = grid.size();
        int COLS = grid[0].size();
        queue<pair<int,int>> q{};
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 0) q.push({i, j});
            }
        }
        
        array<pair<int, int>, 4> dir = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (auto [x2,y2] : dir) {
                int dx = x + x2, dy = y + y2;
                if (dx < 0 || dy < 0 || dx >= ROWS || dy >= COLS) continue;
                if (grid[dx][dy] != INF) continue;
                grid[dx][dy] = grid[x][y] + 1;
                q.push({dx, dy});
            }
        }
    }
};
