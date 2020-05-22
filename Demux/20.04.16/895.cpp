// https://leetcode.com/problems/maximum-frequency-stack/

// Method 1 (hash map, O(1))

class FreqStack {
public:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> rev_freq;
    int max_freq;
    FreqStack() {
        max_freq = 0;
    }
    
    void push(int x) {
        freq[x]++;
        max_freq = max(max_freq, freq[x]);
        rev_freq[freq[x]].push(x);
    }
    
    int pop() {
        int top = rev_freq[max_freq].top();
        rev_freq[max_freq].pop();
        freq[top]--;
        if(rev_freq[max_freq].empty()){
            rev_freq.erase(max_freq);
            max_freq--;
        }
        return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */

// Method 2 (BST, O(logn))

struct comp{
    bool operator()(const int & a, const int & b) const {
        return a > b;
    }
};

class FreqStack {
public:
    unordered_map<int, int> freq;
    // also works
    // map<int, stack<int>, greater<int>> rev_freq;
    map<int, stack<int>, comp> rev_freq;
    FreqStack() {
    }
    
    void push(int x) {
        freq[x]++;
        rev_freq[freq[x]].push(x);
    }
    
    int pop() {
        auto itr = rev_freq.begin(); 
        int top = itr->second.top();
        itr->second.pop();
        freq[top]--;
        if(itr->second.empty()){
            rev_freq.erase(itr->first);
        }
        return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */