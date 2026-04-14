class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> res(n, INT_MAX);
        res[src] = 0;
        for (int i{}; i <= k; i++) {
            vector<int> tmp = res;
            for (const auto& flight : flights) {
                int s = flight[0];
                int d = flight[1];
                int w = flight[2];
                if (res[s] == INT_MAX) continue;
                if (res[s] + w < tmp[d]) {
                    tmp[d] = res[s] + w;
                } 
            }
            res = tmp;
        }
        return res[dst] == INT_MAX ? -1 : res[dst];
    }
};
