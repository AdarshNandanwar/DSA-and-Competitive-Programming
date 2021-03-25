// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

// Method 1 (Min Heap, O(klogn)):

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), r, c;
        // {val, {row, col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        // push row 0
        for(int i = 0; i<min(n, k); i++) pq.push({matrix[0][i], {0, i}});
        
        // replace the min element k-1 times
        while(k--){
            auto t = pq.top();
            if(k == 0) return t.first;
            pq.pop();
            r = t.second.first+1;
            c = t.second.second;
            if(r < n) pq.push({matrix[r][c], {r, c}});
        }
        return -1;
    }
};

// Method 2 (Max Heap, O(k*k*log(k))):

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<int, vector<int>> pq;
        for(int i = 0; i<min(n, k); i++){
            for(int j = 0; j<min(n, k); j++){
                pq.push(matrix[i][j]);
                if(pq.size()>k) pq.pop();
            }
        }
        return pq.top();
    }
};