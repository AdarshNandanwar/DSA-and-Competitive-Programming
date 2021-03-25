// https://leetcode.com/problems/previous-permutation-with-one-swap/

// Method 1 (Tree Map, O(nlogn)):

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        map<int, int> m;
        int n = A.size();
        for(int i = n-1; i>=0; i--){
            if(!m.empty()){
                auto it = m.lower_bound(A[i]);
                if(it != m.begin()){
                    it--;
                    swap(A[i], A[it->second]);
                    return A;
                }
            }
            m[A[i]] = i;
        }
        return A;
    }
};