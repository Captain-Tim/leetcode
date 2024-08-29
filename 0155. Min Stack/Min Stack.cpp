class MinStack {
private:
    stack<int> stk_min;
    stack<int> stk;
public:
    MinStack(){
        
    }
    
    void push(int val) {
        stk.push(val);
        if (stk_min.empty() || stk_min.top() >= val)
            stk_min.push(val);
    }
    
    void pop() {
        if (stk.top() == stk_min.top())
            stk_min.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return stk_min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */