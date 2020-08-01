// https://leetcode.com/problems/min-stack/

class MinStack {
public:
    /** initialize your data structure here. */

    stack<int> st;
    // minVal[i] = min val in bottom i+1 values in stack
    vector<int> minVal;
    
    MinStack() {}
    
    void push(int x) {
        st.push(x);
        if(st.size() == 1) minVal.push_back(x);
        else minVal.push_back(min(x, minVal.back()));
    }
    
    void pop() {
        st.pop();
        minVal.pop_back();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minVal.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */