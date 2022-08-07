// https://leetcode.com/problems/longest-consecutive-sequence/

// Method 1 (Hash set, O(n)):

class Solution {
public:    
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s;
        for(auto &i:nums) s.insert(i);
        for(auto &i:nums){
            if(s.count(i-1)) continue;      // very important O(n2) ===> O(n)
            int cur = i+1;
            while(s.count(cur)) cur++;
            res = max(res, cur-i);
        }
        return res;
    }
};

// Method 2 (Sorting, O(nlogn)):

class Solution {
public:    
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), res = 1, cur = 1;
        if(n == 0) return 0;
        sort(nums.begin(), nums.end());
        for(int i = 1; i<n; i++){
            if(nums[i-1] == nums[i]) continue;
            if(nums[i-1] == nums[i]-1) cur++;
            else cur = 1;
            res = max(res, cur);
        }
        return res;
    }
};

// Method 3 (Ordered Set, O(nlogn)):

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        set<int> sortedNums(nums.begin(), nums.end());
        int res = 1, curLen = 1;
        for(auto itr=next(sortedNums.begin()); itr!=sortedNums.end(); itr++){
            if(*itr == (*prev(itr))+1){
                curLen++;
            } else {
                curLen = 1;
            }
            res = max(res, curLen);
        }
        return res;
    }
};

// Method 4 (Union Find, O(nlogn)):

class Solution {
public:
    
    int root(int x, unordered_map<int, int> & id){
        if(id[x] == x) return x;
        return id[x] = root(id[x], id);
    }
    
    void merge(int r1, int r2, unordered_map<int, int> & id, unordered_map<int, int> & sz){
        if(sz[r1] > sz[r2]) swap(r1, r2);
        id[r1] = r2;
        sz[r2] += sz[r1];
    }
    
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), r;
        unordered_map<int, int> sz, id;
        for(auto &i:nums){
            id[i] = i;
            sz[i] = 1;
        }
        for(auto &i:nums){
            r = root(i, id);
            if(id.count(i-1)){
                int r1 = root(i-1, id);
                if(r != r1) merge(r, r1, id, sz);
            }
            r = root(i, id);
            if(id.count(i+1)){
                int r1 = root(i+1, id);
                if(r != r1) merge(r, r1, id, sz);
            }
        }
        int res = 0;
        for(auto &i:sz) res = max(res, i.second);
        return res;
    }
};

// Method 5 (O(n*n)):

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto i:nums) s.insert(i);
        int res = 0, lo, hi;
        for(auto i:nums){
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
};