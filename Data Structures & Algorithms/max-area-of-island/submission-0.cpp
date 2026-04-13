class Solution {
private:

int ROWS;
int COLS;
vector<vector<bool>> visited;

int dfs(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || j < 0 || i >= ROWS || j >= COLS) return 0;
    // we already visited this
    if (visited[i][j]) return 0;
    // water
    if (grid[i][j] == 0) return 0;
    visited[i][j] = true;
    return dfs(grid, i+1, j) + dfs(grid, i-1, j) + dfs(grid, i, j+1) + dfs(grid, i, j-1) + 1;
}

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        visited = vector<vector<bool>>(ROWS, vector<bool>(COLS, false));
        int res = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (!visited[i][j]) {
                    res = max(res, dfs(grid, i, j));
                }
            }
        }
        return res;
    }
};
