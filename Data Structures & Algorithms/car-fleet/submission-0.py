class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cars = [(p, s) for (p, s) in zip(position, speed)]
        # desc order so cars closest to the end are here
        cars.sort(reverse=True)
        stack = []
        for p, s in cars:
            # time to reach dest
            time = (target - p) / s
            stack.append(time)
            if len(stack) >= 2 and stack[-1] <= stack[-2]:
                stack.pop()
            
        return len(stack)