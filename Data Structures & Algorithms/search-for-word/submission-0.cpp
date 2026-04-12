class Solution {
public:
    vector<vector<bool>> visit{};
    int ROWS;
    int COLS;
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();
        visit = vector<vector<bool>>(ROWS, vector<bool>(COLS, false));
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (dfs(i, j, board, "", word)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(int i, int j, const vector<vector<char>>& board, string curr, const string& word) {
        if (min(i, j) < 0 || i >= ROWS || j >= COLS) return false;
        if (visit[i][j]) return false;

        char c = board[i][j];
        curr += c;
        if (word.find(curr) != 0) return false;
        if (curr == word) return true;
        visit[i][j] = true;
        bool d1 = dfs(i + 1, j, board, curr, word);
        bool d2 = dfs(i - 1, j, board, curr, word);
        bool d3 = dfs(i, j + 1, board, curr, word);
        bool d4 = dfs(i, j - 1, board, curr, word);
        visit[i][j] = false;
        return d1 || d2 || d3 || d4;
    }
};
