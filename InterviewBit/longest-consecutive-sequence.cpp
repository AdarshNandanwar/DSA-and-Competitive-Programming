// https://www.interviewbit.com/problems/longest-consecutive-sequence/

int Solution::longestConsecutive(const vector<int> &A) {
    unordered_set<int> s;
    for(auto i:A) s.insert(i);
    int res = 0, lo, hi;
    for(auto i:A){
        if(s.count(i)){
            lo = i-1; hi = i+1;
            s.erase(i);
            while(s.count(hi)) s.erase(hi++);
            while(s.count(lo)) s.erase(lo--);
            res = max(res, hi-lo-1);
        }
    }
    return res;
}
