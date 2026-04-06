class Solution {
public:
    bool isValid(const string& s) {
        std::unordered_map<char, char> memo = {
            {']', '['},
            {')', '('},
            {'}', '{'}
        };
        std::stack<char> st{};
        for (const auto& c : s) {
            // if it is ], ), or }
            if (memo.find(c) != memo.end()) {
                // we want to check if the current top of the stack is the other side of the end
                if (!st.empty() && st.top() == memo[c]) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};
