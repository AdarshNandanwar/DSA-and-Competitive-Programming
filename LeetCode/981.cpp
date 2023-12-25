// https://leetcode.com/problems/time-based-key-value-store/

// Method 1 (Data Structure, Hash Map, Binary Search, O(logn)):

class TimeMap {
    unordered_map<string, set<pair<int, string>>> data;
public:
    TimeMap() {
        data.clear();
    }
    
    void set(string key, string value, int timestamp) {
        data[key].insert(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        if(data.count(key) == 0){
            return "";
        }
        auto itr = data[key].upper_bound(make_pair(timestamp, string(100, 127)));
        if(itr == data[key].begin()){
            return "";
        }
        return prev(itr)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */