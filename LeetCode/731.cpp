// https://leetcode.com/problems/my-calendar-ii/

// Method 1 (Tree Map, O(n2)):

class MyCalendarTwo {
public:
    map<int, int> timeline;
    
    MyCalendarTwo() {
        this->timeline.clear();
    }
    
    bool book(int start, int end) {
        timeline[start]++;
        timeline[end]--;
        int maxCount = 0, currentEventCount = 0;
        for(auto &it:timeline){
            currentEventCount += it.second;
            maxCount = max(maxCount, currentEventCount);
        }
        if(maxCount>2){
            timeline[start]--;
            timeline[end]++;
            return false;
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */