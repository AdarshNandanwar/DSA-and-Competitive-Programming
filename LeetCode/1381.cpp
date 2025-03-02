// https://leetcode.com/problems/design-a-stack-with-increment-operation/

// Method 1 (Stack and vector, O(1) time, O(n) space):

class CustomStack {
    int maxSize;
    vector<int> deltas;
    stack<int> st;
public:
    CustomStack(int maxSize) {
        // deltas[i] = the delta that should be added to bottom i elements in stack
        this->maxSize = maxSize;
        this->deltas = vector<int>(maxSize+1);
    }
    
    void push(int x) {
        if(st.size() < maxSize){
            st.push(x);
        }
    }
    
    int pop() {
        if(st.empty()){
            return -1;
        }

        int index = st.size();
        int delta = deltas[index];
        deltas[index-1] += deltas[index];
        deltas[index] = 0;

        int value = st.top();
        st.pop();

        return value + delta;
    }
    
    void increment(int k, int val) {
        int index = min(k, (int)st.size());
        deltas[index] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
