// https://leetcode.com/problems/my-calendar-i/

// Method 1 (Binary Search, O(nlogn)):

class MyCalendar {
public:
    
    // {end, start}
    set<pair<int, int>> s;
    
    MyCalendar() {
        s.clear();
    }
    
    bool book(int start, int end) {
        auto it = this->s.upper_bound({start, INT_MAX});
        if(it != s.end() and it->second < end) return false;
        s.insert({end, start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

//  Alternate Code

struct Comp{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)const {
        return a.second < b.second;
    }
};

class MyCalendar {
public:
    
    // {start, end}
    set<pair<int, int>, Comp> s;
    
    MyCalendar() {
        s.clear();
    }
    
    bool book(int start, int end) {
        auto it = this->s.upper_bound({0, start});
        if(it != s.end() and it->first < end) return false;
        s.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

// Method 2 (Counting, O(n2)):

class MyCalendar {
    unordered_set<int> startSet, endSet;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(startSet.count(start)){
            return false;
        }
        if(endSet.count(end)){
            return false;
        }
        int startsBeforeCurStart = 0;
        int startsBeforeCurEnd = 0;
        int startsOnOrAfterCurEnd = 0;
        int endsAfterCurStart = 0;
        int endsAfterCurEnd = 0;
        int endsOnOrBeforeCurStart = 0;
        
        for(auto &time:startSet){
            if(time<start){
                startsBeforeCurStart++;
            }
            if(time<end){
                startsBeforeCurEnd++;
            } else {
                startsOnOrAfterCurEnd++;
            }
        }
        for(auto &time:endSet){
            if(time<=start){
                endsOnOrBeforeCurStart++;
            } else {
                endsAfterCurStart++;
            }
            if(time>end){
                endsAfterCurEnd++;
            }
        }
        
        if(startsBeforeCurStart != startsBeforeCurEnd){
            return false;
        }
        if(endsAfterCurStart != endsAfterCurEnd){
            return false;
        }
        if(startsBeforeCurStart != endsOnOrBeforeCurStart){
            return false;
        }
        if(startsOnOrAfterCurEnd != endsAfterCurEnd){
            return false;
        }
        
        startSet.insert(start);
        endSet.insert(end);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

// Method 3 (Hash Map, Prefix sum trick for ranged queries, O(n2)):

class MyCalendar {
public:
    map<int, int> timeline;
    
    MyCalendar() {
        timeline.clear();
    }
    
    bool book(int start, int end) {
        timeline[start]++;
        timeline[end]--;
        int prev = 0;
        bool isValid = true;
        for(auto &time:timeline){
            time.second += prev;
            prev = time.second;
            if(time.second > 1){
                isValid = false;
            }
        }
        prev = 0;
        for(auto &time:timeline){
            int temp = time.second;
            time.second -= prev;
            prev = temp;
        }
        if(isValid){
            return true;
        } else {
            timeline[start]--;
            timeline[end]++;
            return false;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */