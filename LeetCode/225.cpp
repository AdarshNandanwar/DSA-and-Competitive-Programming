// https://leetcode.com/problems/implement-stack-using-queues/

// Method 1 (Using 1 queue, O(n)):

class MyStack {
    queue<int> q;
public:
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int sz = q.size(), cur = -1;
        for(int i=0; i<sz-1; i++){
            cur = q.front();
            q.pop();
            q.push(cur);
        }
        cur = q.front();
        q.pop();
        return cur;
    }
    
    int top() {
        int sz = q.size(), cur = -1;
        for(int i=0; i<sz; i++){
            cur = q.front();
            q.pop();
            q.push(cur);
        }
        return cur;
    }
    
    bool empty() {
        return q.size() == 0;
    }
};

// Method 2 (Using 1 queue, O(n)):

class MyStack {
    queue<int> q;
public:
    MyStack() {
    }
    
    void push(int x) {
        int sz = q.size();
        q.push(x);
        while(sz--){
            int val = q.front();
            q.pop();
            q.push(val);
        }
    }
    
    int pop() {
        int cur = q.front();
        q.pop();
        return cur;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size() == 0;
    }
};

// Method 3 (Using 2 queues, O(n)):

class MyStack {
    queue<int> q1, q2;
public:
    MyStack() {
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            auto val = q1.front();
            q1.pop();
            q2.push(val);
        }
        swap(q1, q2);
    }
    
    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.size() == 0;
    }
};