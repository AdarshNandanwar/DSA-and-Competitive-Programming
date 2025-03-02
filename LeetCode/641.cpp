// https://leetcode.com/problems/design-circular-deque/

// Method 1 (Vector, O(1)):

class MyCircularDeque {
    vector<int> v;
    int capacity;
    int start;
    int end;

    int getSize(){
        if(start == end){
            return v[start] == -1 ? 0 : capacity;
        } else if(end < start){
            return end + capacity - start;
        } else {
            return end - start;
        }
    }
public:
    MyCircularDeque(int k) {
        v = vector<int>(k, -1);
        capacity = k;
        start = 0;
        end = 0;
    }
    
    bool insertFront(int value) {
        if(getSize() >= capacity){
            return false;
        }

        start--;
        start = (start + capacity) % capacity;
        v[start] = value;

        return true;
    }
    
    bool insertLast(int value) {
        if(getSize() >= capacity){
            return false;
        }

        v[end] = value;
        end++;
        end = end % capacity;
        
        return true;
    }
    
    bool deleteFront() {
        if(getSize() == 0){
            return false;
        }

        v[start] = -1;
        start++;
        start = start % capacity;
        
        return true;
    }
    
    bool deleteLast() {
        if(getSize() == 0){
            return false;
        }

        end--;
        end = (end + capacity) % capacity;
        v[end] = -1;
        
        return true;
    }
    
    int getFront() {
        return v[start];
    }
    
    int getRear() {
        int index = (end - 1 + capacity) % capacity;
        return v[index];
    }
    
    bool isEmpty() {
        return getSize() == 0;
    }
    
    bool isFull() {
        return getSize() == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
