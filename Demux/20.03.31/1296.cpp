// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        // Or use vector<pair<int, int>> and then sort it
        map<int, int> m;
        set<int> s;
        for(auto i:nums){
            m[i]++;
            s.insert(i);
        }
        for(auto i:m){
            int cur = i.first;
            int cur_cnt = i.second;
            if(cur_cnt == 0)    continue;
            for(int j = 0; j<k ; j++){
                if(s.find(cur+j) == s.end()){
                    return false;
                }
                if(m[cur+j] < cur_cnt){
                    return false;
                }
                m[cur+j] -= cur_cnt;
            }
        }
        return true;
    }
};