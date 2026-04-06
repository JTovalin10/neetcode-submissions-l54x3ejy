class MinStack {
public:
    MinStack() = default;
    
    void push(int val) {
        reg.push(val);
        int mval = (!min.empty()) ? std::min(val, min.top()) : val;        
        min.push(mval);
    }
    
    void pop() {
        if (reg.size() == 0) return;
        reg.pop();
        min.pop();
    }
    
    int top() {
        return reg.top();
    }
    
    int getMin() {
        return min.top();
    }

    private:
    std::stack<int> reg{};
    std::stack<int> min{};
};
