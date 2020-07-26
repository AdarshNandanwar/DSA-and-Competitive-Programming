// https://www.interviewbit.com/problems/merge-overlapping-intervals/

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
 
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A.empty()) return {};
    
    sort(A.begin(), A.end(), [](const Interval & a, const Interval & b){return a.start < b.start;});
    
    vector<Interval> res;
    A.push_back(Interval(INT_MAX, INT_MIN));
    Interval cur = A[0];
    for(auto i:A){
        if(isOverlap(cur, i)){
            cur.start = min(i.start, cur.start);
            cur.end = max(i.end, cur.end);
        } else {
            res.push_back(cur);
            cur = i;
        }
    }
    return res;
}
