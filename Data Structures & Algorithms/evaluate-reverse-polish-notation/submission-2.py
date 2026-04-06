class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for c in tokens:
            if c == '+':
                stack.append(stack.pop() + stack.pop())
            elif c == '-':
                 a, b = stack.pop(), stack.pop()
                 stack.append(b - a)
            elif c == '*':
                 stack.append(stack.pop() * stack.pop())
            elif c == '/':
                 num1 = stack.pop()
                 num2 = stack.pop()
                
                 stack.append(int(float(num2) / num1))
            else:
                stack.append(int(c))
        return stack[0]