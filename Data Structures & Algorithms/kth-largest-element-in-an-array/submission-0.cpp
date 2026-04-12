class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for (int num : nums) {
            maxHeap.push(num);
        }

        while (k - 1 > 0) {
            maxHeap.pop();
            k--;
        }
        return maxHeap.top();
    }

private:
priority_queue<int> maxHeap{};
};
