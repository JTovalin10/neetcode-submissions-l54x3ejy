class Solution {
private:
vector<vector<int>> memo{};
int rows;
int cols;

int dfs(const vector<vector<int>>& obstacleGrid, int i, int j) {
    if (i >= rows || j >= cols) return 0;
    if (obstacleGrid[i][j] == 1) return 0;
    if (i == (rows - 1) && j == (cols - 1)) return 1;
    if (memo[i][j] != -1) return memo[i][j];
    return memo[i][j] = dfs(obstacleGrid, i + 1, j) +  dfs(obstacleGrid, i, j + 1);
}

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        rows = obstacleGrid.size();
        cols = obstacleGrid[0].size();
        memo.resize(rows, vector<int>(cols, -1));
        return dfs(obstacleGrid, 0, 0);    
    }
};