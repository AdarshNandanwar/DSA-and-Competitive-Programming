// https://leetcode.com/problems/matchsticks-to-square/

// Method 1 (Recursion, O(4^n)):

class Solution {
    bool helper(const vector<int> & matchsticks, vector<int> & sides, const int & sideLength, int index){
        if(index == matchsticks.size()){
            return true;
        }
        int curStick = matchsticks[index];
        bool res = false;
        for(int i=0; i<4; i++){
            if(sides[i]+curStick <= sideLength){
                sides[i] += curStick;
                res = helper(matchsticks, sides, sideLength, index+1);
                if(res){
                    break;
                }
                sides[i] -= curStick;
            }
        }
        return res;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size(), sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum%4){
            return false;
        }
        int sideLength = sum/4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> sides(4, 0);
        return helper(matchsticks, sides, sideLength, 0);
    }
};

// Method 2 (Optimization, Pruning):

class Solution {
public:
    
    string get_key(vector<long> &sides, int index){
        sort(sides.begin(), sides.end());
        string res = to_string(index);
        for(auto &i:sides) res += ("#"+to_string(i));
        return res;
    }
    
    bool helper(vector<int>& matchsticks, int index, vector<long> sides, const long &limit, unordered_map<string, bool> &m){
        for(auto &i:sides) if(i>limit) return 0;
        if(matchsticks.size() == index){
            long cur = sides[0];
            for(auto &i:sides) if(i != cur) return 0;
            return 1;
        }
        string key = get_key(sides, index);
        if(m.count(key)) return m[key];
        for(int i = 0; i<4; i++){
            sides[i] += matchsticks[index];
            if(helper(matchsticks, index+1, sides, limit, m)) return m[key] = 1;
            sides[i] -= matchsticks[index];
        }
        return m[key] = 0;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        long sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum%4) return 0;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        if(matchsticks[0] > sum/4) return 0;
        unordered_map<string, bool> m;
        vector<long> sides(4, 0);
        return helper(matchsticks, 0, sides, sum/4, m);
    }
};

// Method 3 (Brute Force, TLE):

class Solution {
    struct Cmp{
        bool operator()(const int & a, const int & b) const {
            return a > b;
        }
    };
    bool helper(multiset<int, Cmp> & sticks, const int & sideLength, int curSideLength){
        if(sticks.empty()){
            return true;
        }
        vector<int> sticksVector(sticks.begin(), sticks.end());
        for(auto & stick:sticksVector){
            int newSideLength = curSideLength+stick;
            if(newSideLength > sideLength){
                continue;
            }
            auto itr = sticks.lower_bound(stick);
            sticks.erase(itr);
            if(newSideLength == sideLength){
                if(helper(sticks, sideLength, 0)){
                    return true;
                }                
            } else {
                if(helper(sticks, sideLength, newSideLength)){
                    return true;
                }                
            }
            sticks.insert(stick);
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size(), sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum%4){
            return false;
        }
        int sideLength = sum/4;
        multiset<int, Cmp> sticks(matchsticks.begin(), matchsticks.end());
        return helper(sticks, sideLength, 0);
    }
};

// Method 4 (Brute Force, TLE):

class Solution {
public:
    
    bool helper(vector<int>& matchsticks, int index, long s1, long s2, long s3, long s4, const long &limit){
        if(s1>limit or s2>limit or s3>limit or s4>limit) return 0;
        if(matchsticks.size() == index){
            return s1 == s2 and s2 == s3 and s3 == s4;
        }
        return helper(matchsticks, index+1, s1+matchsticks[index], s2, s3, s4, limit) or
            helper(matchsticks, index+1, s1, s2+matchsticks[index], s3, s4, limit) or
            helper(matchsticks, index+1, s1, s2, s3+matchsticks[index], s4, limit) or
            helper(matchsticks, index+1, s1, s2, s3, s4+matchsticks[index], limit);
    }
    
    bool makesquare(vector<int>& matchsticks) {
        long s1 = 0, s2 = 0, s3 = 0, s4 = 0, sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum%4) return 0;
        return helper(matchsticks, 0, s1, s2, s3, s4, sum/4);
    }
};