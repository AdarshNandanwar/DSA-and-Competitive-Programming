// https://www.interviewbit.com/problems/merge-intervals/

// Method 1 (using vector.back(), O(n)):

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 bool isOverlap(Interval & a, Interval & b){
     return !(a.end < b.start or b.end < a.start);
 }
 
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {

    int n = intervals.size();
    if(n == 0) return {newInterval};
    
    bool addedNew = 0;
    vector<Interval> res;
    for(auto i:intervals){
        if(!res.empty() and isOverlap(i, res.back())){
            auto prev = res.back();
            res.pop_back();
            i.start = min(i.start, prev.start);
            i.end = max(i.end, prev.end);
        }
        if(!addedNew){
            if(isOverlap(newInterval, i)){
                i.start = min(newInterval.start, i.start);
                i.end = max(newInterval.end, i.end);
                addedNew = 1;
            } else if(newInterval.start < i.start){
                res.push_back(newInterval);
                addedNew = 1;
            }
        }
        res.push_back(i);
    }
    if(!addedNew) res.push_back(newInterval);
    return res;
}

// Method 2 (using cur, O(n)):

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 bool isOverlap(Interval & a, Interval & b){
     return !(a.end < b.start or b.end < a.start);
 }
 
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {

    if(newInterval.start > newInterval.end) swap(newInterval.start, newInterval.end);
    if(intervals.empty()) return {newInterval};
    
    bool newAdded = 0;
    vector<Interval> res;
    intervals.push_back(Interval(INT_MAX, INT_MIN));
    Interval cur = intervals[0];
    for(auto i:intervals){
        if(isOverlap(cur, newInterval)){
            cur.start = min(newInterval.start, cur.start);
            cur.end = max(newInterval.end, cur.end);
            newAdded = 1;
        }
        if(isOverlap(cur, i)){
            cur.start = min(i.start, cur.start);
            cur.end = max(i.end, cur.end);
        } else {
            if(!newAdded and newInterval.start < cur.start){
                res.push_back(newInterval);
                newAdded = 1;
            }
            res.push_back(cur);
            cur = i;
        }
    }
    if(!newAdded) res.push_back(newInterval);
    return res;
}