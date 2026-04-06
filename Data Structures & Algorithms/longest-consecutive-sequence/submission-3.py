class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums_set: set[nums] = set(nums)
        res: int = 0
        for num in nums:
            if num - 1 not in nums_set:
                # now we can go forward as we know we found the smallest number iun the set
                curr = num
                count = 0
                while curr in nums_set:
                    count += 1
                    curr += 1
                res = max(res, count)
        return res