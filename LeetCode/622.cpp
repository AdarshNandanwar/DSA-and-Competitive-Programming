// https://leetcode.com/problems/design-circular-queue/

// Method 1 (Hash Function, O(1)):

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

// Method 1 (Hash Function, O(1)):

class MyCircularQueue {
    vector<int> buffer;
    int head, tail, size;
    bool isBufferFull;
public:
    MyCircularQueue(int k) {
        size = k;
        head = 0;
        tail = 0;
        buffer = vector<int>(k, -1);
        isBufferFull = false;
    }
    
    bool enQueue(int value) {
        if(isBufferFull){
            return false;
        }
        buffer[tail%size] = value;
        tail = (tail+1)%size;
        if(tail == head){
            isBufferFull = true;
        }
        return true;
    }
    
    bool deQueue() {
        if(!isBufferFull and head == tail){
            return false;
        }
        buffer[head] = -1;
        head = (head+1)%size;
        if(isBufferFull){
            isBufferFull = false;
        }
        return true;
    }
    
    int Front() {
        return buffer[head];
    }
    
    int Rear() {
        int index = (size+tail-1)%size;
        return buffer[index];
    }
    
    bool isEmpty() {
        return !isBufferFull and head == tail;
    }
    
    bool isFull() {
        return isBufferFull;
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