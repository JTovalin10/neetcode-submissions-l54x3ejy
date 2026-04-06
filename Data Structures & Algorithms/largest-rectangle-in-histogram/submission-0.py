class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        # (leftMost, height)
        stack = []
        res = -1
        for i, height in enumerate(heights):
            start = i
            while stack and stack[-1][1] > height:
                index, h = stack.pop()
                res = max(res, h * (i - index))
                start = index
            stack.append((start, height))
        
        # now find the max
        for index, height in stack:
            res = max(res, height * (len(heights) - index))
        return res