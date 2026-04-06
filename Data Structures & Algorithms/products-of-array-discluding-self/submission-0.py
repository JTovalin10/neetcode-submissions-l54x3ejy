class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [1] * n
        forward = 1
        for i in range(n):
            res[i] *= forward
            forward *= nums[i]
        backwards = 1
        for i in range(n - 1, -1, -1):
            res[i] *= backwards
            backwards *= nums[i]
        return res