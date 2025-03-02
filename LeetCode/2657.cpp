// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/

// Merhod 1 (Frequency Count, O(n)):

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n), C(n);
        int prefixCount = 0;
        for(int i=0; i<n; i++){
            freq[A[i]-1]++;
            freq[B[i]-1]++;
            if(freq[A[i]-1] == 2){
                prefixCount++;
            }
            if(A[i] != B[i] and freq[B[i]-1] == 2){
                prefixCount++;
            }

            C[i] = prefixCount;
        }
        return C;
    }
};
