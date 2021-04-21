// https://leetcode.com/problems/global-and-local-inversions/

// Merge Sort

class Solution {
public:
    
    int merge(vector<int>& A, int st, int mid, int end){
        int p1 = st, p2 = mid, res = 0;
        vector<int> temp;
        while(p1<mid and p2<end){
            if(A[p1] > A[p2]){
                res += (mid-p1);
                temp.push_back(A[p2++]);
            } else {
                temp.push_back(A[p1++]);
            }
        }
        while(p1<mid) temp.push_back(A[p1++]);
        while(p2<end) temp.push_back(A[p2++]);
        for(auto & i:temp) A[st++] = i;
        return res;
    }
    
    int count_inversions(vector<int>& A, int st, int end){
        if(end-st <= 1) return 0;
        int mid = st+(end-st+1)/2, res = 0;
        res += count_inversions(A, st, mid);
        res += count_inversions(A, mid, end);
        res += merge(A, st, mid, end);
        return res;
    }
    
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size(), local_inversions = 0;
        for(auto i = 0; i<n-1; i++) if(A[i] > A[i+1]) local_inversions++;
        int global_inversions = count_inversions(A, 0, n);
        return local_inversions == global_inversions;        
    }
};