class Solution {
private:
int ROWS;
int COLS;

void dfs(vector<vector<char>>& grid, int i, int j) {
    if (min(i, j) < 0 || i >= ROWS || j >= COLS) return;
    if (grid[i][j] == '0') return;

    grid[i][j] = '0';
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}

public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        ROWS = grid.size();
        COLS = grid[0].size();
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    num++;
                }
            }
        }
        return num;
    }
};
