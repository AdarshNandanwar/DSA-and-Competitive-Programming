// https://leetcode.com/problems/maximum-frequency-stack/

// Method 1 (Hash Map and Stack, O(1) time):

class FreqStack {
    int maxFreq;
    unordered_map<int, int> valueToFreq;
    unordered_map<int, stack<int>> freqToValues;
public:
    FreqStack() {
        maxFreq = 0;
        valueToFreq.clear();
        freqToValues.clear();
    }
    
    void push(int val) {
        int newFreq = 1;

        if(valueToFreq.count(val) != 0){
            int prevFreq = valueToFreq[val];
            newFreq = prevFreq + 1;
        }

        valueToFreq[val] = newFreq;
        freqToValues[newFreq].push(val);
        maxFreq = max(newFreq, maxFreq);
    }
    
    int pop() {
        if(valueToFreq.size() == 0){
            return -1;
        }

        int valueToPop = freqToValues[maxFreq].top();
        freqToValues[maxFreq].pop();
        if(freqToValues[maxFreq].size() == 0){
            freqToValues.erase(maxFreq);
            maxFreq--;
        }
        valueToFreq[valueToPop]--;
        if(valueToFreq[valueToPop] == 0){
            valueToFreq.erase(valueToPop);
        }
        
        return valueToPop;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
