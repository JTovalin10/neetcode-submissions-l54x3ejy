struct TrieNode {
    unordered_map<char, TrieNode*> children{};
    bool end = false;

    void insert(const string& word) {
        TrieNode* curr = this;
        for (char c : word) {
            if (curr->children.count(c) == 0) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->end = true;
    }
};

class Solution {
public:

    vector<string> res{};
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            root->insert(word);
        }
        ROWS = board.size();
        COLS = board[0].size();
        visit = vector<vector<bool>>(ROWS, vector<bool>(COLS, false));
        for (int i{0}; i < ROWS; i++) {
            for (int j{}; j < COLS; j++) {
                dfs(board, root, i, j, "");
            }
        }
        return vector<string>(res.begin(), res.end());
    }
private:
    void dfs(const vector<vector<char>>& board, TrieNode* node, int i, int j, string word) {
        if (min(i, j) < 0 || i >= ROWS || j >= COLS) return;
        char c = board[i][j];
        if (visit[i][j] || !node->children.count(c)) return;

        visit[i][j] = true;
        node = node->children[c];
        word += c;
        if (node->end) {
            res.push_back(word);
            node->end = false;
        }

        dfs(board, node, i + 1, j, word);
        dfs(board, node, i, j + 1, word);
        dfs(board, node, i - 1, j, word);
        dfs(board, node, i, j - 1, word);
        visit[i][j] = false;
    }

    int ROWS;
    int COLS;
    vector<vector<bool>> visit{};
};