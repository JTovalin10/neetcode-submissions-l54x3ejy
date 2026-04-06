class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        memo = defaultdict(int)
        array = [[] for _ in range(len(nums) + 1)]
        for num in nums:
            memo[num] += 1
        
        for number, count in memo.items():
            array[count].append(number)
        
        res = []
        for i in range(len(array) - 1, 0, -1):
            for num in array[i]:
                res.append(num)
                if len(res) == k:
                    return res
        return []