// https://leetcode.com/problems/data-stream-as-disjoint-intervals/

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    
    unordered_map<int, int> id, minId, maxId, sz;
    set<vector<int>> s;
    
    SummaryRanges() {
        id.clear();
        minId.clear();
        maxId.clear();
        s.clear();
    }
    
    int root(int x){
        if(id[x] == x) return x;
        return id[x] = root(id[x]);
    }
    
    void merge(int r1, int r2){
        r1 = root(r1);
        r2 = root(r2);
        s.erase({minId[r1], maxId[r1]});
        s.erase({minId[r2], maxId[r2]});
        if(sz[r1] > sz[r2]) swap(r1, r2);
        id[r1] = id[r2];
        sz[r2] += sz[r1];
        minId[r2] = min(minId[r1], minId[r2]);
        maxId[r2] = max(maxId[r1], maxId[r2]);
        s.insert({minId[r2], maxId[r2]});
    }
    
    void addNum(int val) {
        if(!id.count(val)){
            id[val] = val;
            minId[val] = maxId[val] = val;
            s.insert({minId[val], maxId[val]});
            if(id.count(val+1)) merge(val, val+1);
            if(id.count(val-1)) merge(val, val-1);
        }
    }
    
    vector<vector<int>> getIntervals() {
        return vector<vector<int>>(s.begin(), s.end());  
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */