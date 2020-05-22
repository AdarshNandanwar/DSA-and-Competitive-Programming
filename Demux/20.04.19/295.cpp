// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
    
    // lower has always grater size than upper
    priority_queue<int, vector<int>> lower;
    priority_queue<int, vector<int>, greater<int>> upper;
    
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lower.push(num);
        upper.push(lower.top());
        lower.pop();
        
        if(upper.size() > lower.size()){
            lower.push(upper.top());
            upper.pop();
        }
    }
    
    double findMedian() {
        if(lower.size()>upper.size()){
            return lower.top();
        } else {
            return (lower.top()+upper.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */