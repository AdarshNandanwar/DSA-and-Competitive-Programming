// https://leetcode.com/problems/sort-array-by-parity/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size(), p1 = 0, p2 = n-1;
        while(p1<p2){
            while(p1<n and A[p1]%2 == 0) p1++;
            while(p2>=0 and A[p2]%2 == 1) p2--;
            if(p1<p2) swap(A[p1++], A[p2--]);
        }
        return A;
    }
};