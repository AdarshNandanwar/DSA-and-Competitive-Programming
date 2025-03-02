// https://leetcode.com/problems/lexicographical-numbers/

// Method 1 (DFS, O(n)):

class Solution {
    void helper(int cur, const int n, vector<int> & ans){
        if(cur > n){
            return;
        }
        
        ans.push_back(cur);

        for(int i=0; i<10; i++){
            helper((10 * cur) + i, n, ans);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1; i<10; i++){
            helper(i, n, ans);
        }
        return ans;
    }
};

// Method 2 (Sorting, O(nlogn)):

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> v(n);
        for(int i=0; i<n; i++){
            v[i] = i+1;
        }
        sort(v.begin(), v.end(), [](const int a, const int b){
            return to_string(a) < to_string(b);
        });
        return v;
    }
};
