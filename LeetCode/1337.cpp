// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

// Method 1 (Binary Search + Max Heap, O(n*log(max(m, k)))):

class Solution {
public:
    int countOnes(vector<int> &v){
        // FT, First T
        int lo = 0, hi = v.size()-1, mid;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(v[mid] == 0){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        if(v[lo] == 0) return lo;
        else return v.size();
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m=mat[0].size();
        priority_queue<vector<int>, vector<vector<int>>> pq;
        for(auto i=0; i<n; i++){
            vector<int> v = {0, i};
            int ones = countOnes(mat[i]);
            pq.push({ones, i});
            if(pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top()[1]);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Method 2 (Max heap, O(n*(m+log(k))):

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m=mat[0].size();
        priority_queue<vector<int>, vector<vector<int>>> pq;
        for(auto i=0; i<n; i++){
            vector<int> v = {0, i};
            for(auto j=0; j<m; j++){
                v[0] += mat[i][j];
            }
            pq.push(v);
            if(pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top()[1]);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Method 3 (Sorting, O(n*(m+logn))):

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m=mat[0].size();
        vector<vector<int>> sum(n, vector<int>(2, 0));
        for(auto i=0; i<n; i++){
            for(auto j=0; j<m; j++){
                sum[i][0] += mat[i][j];
            }
            sum[i][1] = i;
        }
        sort(sum.begin(), sum.end());
        vector<int> ans(k);
        for(auto i=0; i<k; i++) ans[i] = sum[i][1];
        return ans;
    }
};

// Method 4 (Sorting, O(m*n*log(n))):

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        for(auto i=0; i<mat.size(); i++) mat[i].push_back(i);
        sort(mat.begin(), mat.end());
        vector<int> res;
        for(int i=0; i<k; i++) res.push_back(mat[i][mat[i].size()-1]);
        return res;
    }
};