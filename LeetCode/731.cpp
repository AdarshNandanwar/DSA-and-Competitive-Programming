// https://leetcode.com/problems/my-calendar-ii/

// Method 1 (Store overlaps, O(n)):

class MyCalendarTwo {
public:
    vector<vector<int>> events;
    vector<vector<int>> eventOverlaps;

    MyCalendarTwo() {
        events.clear();
        eventOverlaps.clear();
    }
    
    bool book(int start, int end) {

        for(auto overlap:eventOverlaps){
            if(overlap[1] <= start or end <= overlap[0]){
                continue;
            }
            return false;
        }

        for(auto event:events){
            if(event[1] <= start or end <= event[0]){
                continue;
            }

            vector<int> overlap = {max(start, event[0]), min(end, event[1])};
            eventOverlaps.push_back(overlap);
        }

        events.push_back({start, end});

        return true;
    }
};

// Method 1 (Tree Map, O(n)):

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