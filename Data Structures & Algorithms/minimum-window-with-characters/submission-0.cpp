class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size() || t.empty()) return "";
        unordered_map<char, int> tcount, window;
        tcount.reserve(t.size());
        window.reserve(s.size());
        for (char c : t) {
            tcount[c]++;
        }

        int l = 0;
        int reslen = numeric_limits<int>::max();
        int lres = 0;
        int have = 0, need = tcount.size();
        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            if (tcount.find(c) != tcount.end() && tcount[c] == window[c]) {
                have++;
            }

            while (have == need) {
                if ((r - l + 1) < reslen) {
                    reslen = r - l + 1;
                    lres = l;
                }

                window[s[l]]--;
                if (tcount.find(s[l]) != tcount.end() && window[s[l]] < tcount[s[l]]) have--;
                l++;
            }
        }
        return (reslen == numeric_limits<int>::max()) ? "" : s.substr(lres, reslen);
    }
};
