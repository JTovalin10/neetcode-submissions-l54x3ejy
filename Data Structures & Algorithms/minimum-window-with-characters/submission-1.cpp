class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size() || t.empty()) return "";

        unordered_map<char, int> tcount, window;
        tcount.reserve(t.size());
        window.reserve(s.size());
        for (char c : t) {
            tcount[c]++;
        }   
        int reslen = numeric_limits<int>::max();
        int lres = 0;
        int have = 0, want = tcount.size();
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;
            if (tcount.count(c) && tcount[c] == window[c]) {
                have++;
            }

            while (have == want) {
                char c2 = s[l];
                if ((r - l + 1) < reslen) {
                    reslen = (r - l + 1);
                    lres = l;
                }

                window[c2]--;
                // as we removed it, if they are not he same then we dont have it
                if (tcount.count(c2) && window[c2] < tcount[c2]) have--;
                l++;
            }
        }
        return (reslen == numeric_limits<int>::max()) ? "" : s.substr(lres, reslen);
    }
};
