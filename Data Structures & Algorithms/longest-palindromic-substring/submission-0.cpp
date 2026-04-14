class Solution {
public:
    string longestPalindrome(const string& s) {
        int n = s.size();
        int resIdx = 0, resLen =0;
        vector<vector<bool>> check(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && ((j - i) <= 2 || check[i + 1][j - 1])) {
                    check[i][j] = true;
                    if ((j - i + 1 )> resLen) {
                        resIdx = i;
                        resLen = j - i + 1;
                    }
                }
            }
        }
        return s.substr(resIdx, resLen);
    }
};
