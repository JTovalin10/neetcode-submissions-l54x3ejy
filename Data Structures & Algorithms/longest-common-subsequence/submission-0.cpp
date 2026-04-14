class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        m = text1.size();
        n = text2.size();
        memo.assign(m, vector<int>(n, -1));
        return dfs(text1, text2, 0, 0);
    }

private:
int n;
int m;
vector<vector<int>> memo{};

int dfs(const string& t1, const string& t2, int i, int j) {
    if (i == t1.size() || j == t2.size()) return 0;
    if (memo[i][j] != -1) return memo[i][j];
    if (t1[i] == t2[j]) {
        memo[i][j] = 1 + dfs(t1, t2, i + 1, j + 1);
    } else {
        memo[i][j] = max(dfs(t1, t2, i + 1, j), dfs(t1, t2, i, j + 1));
    }
    return memo[i][j];
}
};
