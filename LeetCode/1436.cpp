// https://leetcode.com/problems/destination-city/

// Method 1 (Hash Table, O(n)):

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> s;
        for(auto e:paths) s.insert(e[1]);
        for(auto e:paths) s.erase(e[0]);
        return *s.begin();
    }
};