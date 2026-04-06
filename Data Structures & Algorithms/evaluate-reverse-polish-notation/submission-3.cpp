class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stk{};  // store ints directly, no need for stoi repeatedly
        for (const auto& token : tokens) {
            if (token == "+") {
                int num2 = stk.top(); stk.pop();
                int num1 = stk.top(); stk.pop();
                stk.push(num1 + num2);
            } else if (token == "-") {
                int num2 = stk.top(); stk.pop();
                int num1 = stk.top(); stk.pop();
                stk.push(num1 - num2);
            } else if (token == "*") {
                int num2 = stk.top(); stk.pop();
                int num1 = stk.top(); stk.pop();
                stk.push(num1 * num2);
            } else if (token == "/") {
                int num2 = stk.top(); stk.pop();
                int num1 = stk.top(); stk.pop();
                stk.push(num1 / num2);
            } else {
                stk.push(stoi(token));
            }
        }
        return stk.top();  // final answer is whatever remains
    }
};
