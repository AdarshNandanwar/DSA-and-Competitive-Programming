// https://leetcode.com/problems/largest-component-size-by-common-factor/

// Method 1 (Union Find with rank and path compression):

class Solution {
public:
    int root(vector<int> & id, int x){
        if(x == id[x]) return x;
        return id[x] = root(id, id[x]);
    }
    
    int largestComponentSize(vector<int>& A) {
        int i, j, n, m, res = 1, maxEle = *max_element(A.begin(), A.end());
        vector<int> id(A.size(), 0), sz(A.size(), 1);
        for(i = 0; i < A.size(); ++i) id[i] = i;
        vector<vector<int>> prime(maxEle + 1, vector<int>());
        for(i = 0; i < A.size(); ++i) {
            for(j = 2; j * j <= A[i]; ++j) {
                if(A[i] % j) continue;
                prime[j].push_back(i);
                while(A[i] % j == 0) A[i] /= j;
            }
            if (A[i] > 1) prime[A[i]].push_back(i);
        }
        
        for(i = 2; i < prime.size(); ++i) {
            if(prime[i].size() < 2) continue;
            n = root(id, prime[i][0]);
            for(j = 1; j < prime[i].size(); ++j) {
                m = root(id, prime[i][j]);
                if(m != n) {
                    id[m] = n;
                    sz[n] += sz[m];
                    res = max(res, sz[n]);
                }
            }
        }

        return res;
    }
};