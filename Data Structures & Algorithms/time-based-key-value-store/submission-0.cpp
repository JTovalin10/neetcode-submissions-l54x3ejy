class TimeMap {
public:
    TimeMap() = default;
    
    void set(string key, string value, int timestamp) {
        memo[key].emplace_back(value, timestamp);
    }
    
    string get(string key, int timestamp) {
        const vector<pair<string, int>> value = memo[key];
        int l = 0, r = value.size() - 1;
        string res = "";
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (value[m].second <= timestamp) {
                res = value[m].first;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return res;
    }

private:
unordered_map<string,vector< pair<string, int>>> memo{};
};
