class Solution {
private:

vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int ROWS;
int COLS;

void bfs(const vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& ocean) {
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        ocean[x][y] = true;
        for (auto [x2, y2] : dir) {
            int dx = x + x2, dy = y + y2;
            if (dx < 0 || dy < 0 || dx >= ROWS || dy >= COLS) continue;
            // we cannot go there
            if (heights[dx][dy] < heights[x][y]) continue;
            if (ocean[dx][dy]) continue; // we already can reach this
            q.push({dx, dy});
        } 
    }
}

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
         vector<vector<bool>> alt(ROWS, vector<bool>(COLS, false));

        queue<pair<int, int>> pQueue, aQueue;
        for (int c = 0; c < COLS; c++) {
            pQueue.push({0, c});
            aQueue.push({ROWS - 1, c});
        }
        for (int r =0 ; r < ROWS; r++) {
            pQueue.push({r, 0});
            aQueue.push({r, COLS - 1});
        }

        bfs(heights, pQueue, pac);
        bfs(heights, aQueue, alt);

        vector<vector<int>> res{};
        for (int i = 0; i < ROWS; i++) {
            for (int j =0; j < COLS; j++) {
                if (pac[i][j] && alt[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
};
