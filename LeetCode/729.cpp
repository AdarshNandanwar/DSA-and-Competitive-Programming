// https://leetcode.com/problems/my-calendar-i/

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