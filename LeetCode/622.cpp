// https://leetcode.com/problems/design-circular-queue/

class MyCircularQueue {
public:
    vector<int> q;
    int st, end, sz;
    
    MyCircularQueue(int k) {
        q = vector<int>(k, 0);
        st = end = sz = 0;
    }
    
    bool enQueue(int value) {
        if(sz == q.size()) return false;
        q[end] = value;
        end = (end+1)%q.size();
        sz++;
        return true;
    }
    
    bool deQueue() {
        if(sz == 0) return false;
        st = (st+1)%q.size();
        sz--;
        return true;
    }
    
    int Front() {
        if(sz == 0) return -1;
        return q[st];
    }
    
    int Rear() {
        if(sz == 0) return -1;
        int prev = (end+q.size()-1)%q.size();
        return q[prev];
    }
    
    bool isEmpty() {
        return sz == 0;
    }
    
    bool isFull() {
        return sz == q.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */