// https://leetcode.com/problems/min-stack/

// Method 1 (Encoding, O(1) time, O(1) space):

class MinStack {
public:
    
    /*
    
    When min_value > val, then we have to store 2 numbers somewhere.
    i.e.    1. new min_value which is the current value to be puched
            2. prev min_value, which is needed if the new value is popped in future
    
    We do this by encoding both in a single integer and puch it in stack
    and use the min_value as key to extract the older value
    
    min_value > new_val
    => new_val > 2*new_val-min_val
    
    We do the above transformation as we have to store min value in min_value
    as we need it for get_min() and can't store some other value as key.
    
    min_value = LHS
    st.push(RHS)
    
    */
        
    stack<long> st;
    long min_value;
    
    MinStack() {
        this->min_value = 0;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            this->min_value = val;
        } else {
            if(this->min_value > val){
                st.push(2l*val-this->min_value);
                this->min_value = val;
            } else {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.top() < this->min_value){
            this->min_value = 2l*this->min_value-st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top() < this->min_value) return this->min_value;
        return st.top();
    }
    
    int getMin() {
        return this->min_value;
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

// Method 2 (Min vector, O(1) time, O(n) space):

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