class Solution {
private:
priority_queue<int> maxHeap{};

public:
    int lastStoneWeight(vector<int>& stones) {
        // add them into the maxHeap
        for (int num : stones) {
            maxHeap.push(num);
        }
        while (!maxHeap.empty()) {
            int s1 = maxHeap.top(); maxHeap.pop();
            if (maxHeap.empty()) return s1;
            int s2 = maxHeap.top(); maxHeap.pop();
            if (s1 == s2) continue;
            maxHeap.push(abs(s2 - s1));
        }
        return 0;
    }
};
