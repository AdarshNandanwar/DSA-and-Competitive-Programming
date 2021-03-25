// https://leetcode.com/problems/bulb-switcher-iii/

// Method 1 (O(n)):

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int res = 0, maxL = -1;
        for(int i = 0; i<light.size(); i++){
            maxL = max(maxL, light[i]);
            res += (maxL == i+1);
        }
        return res;
    }
};

// Method 2 (Union Find, O(nlogn)):

class Solution {
public:
    int root(int x, vector<int> & id){
        if(x == id[x]) return x;
        return id[x] = root(id[x], id);
    }
    void merge(int r1, int r2, vector<int> & id, vector<int> & sz, vector<int> & left){
        r1 = root(r1, id);
        r2 = root(r2, id);
        if(sz[r1] < sz[r2]) swap(r1, r2);
        sz[r1] += sz[r2];
        id[r2] = r1;
        left[r1] = min(left[r1], left[r2]);
    }
    
    int numTimesAllBlue(vector<int>& light) {
        int res = 0, n = light.size(), r, onCount = 0;
        vector<bool> isOn(n, 0);
        vector<int> id(n), sz(n, 1), left(n);
        for(int i = 0; i<n; i++){
            light[i]--;
            left[i] = id[i] = i;
        }
        for(auto l:light){
            isOn[l] = 1;
            onCount++;
            if(l-1>=0 and isOn[l-1]) merge(l-1, l, id, sz, left);
            if(l+1<n and isOn[l+1]) merge(l+1, l, id, sz, left);
            r = root(l, id);
            if(left[r] == 0 and sz[r] == onCount) res++;
        }
        return res;
    }
};