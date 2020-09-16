// https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for(auto i:A) sum += i;
        if(sum%3) return 0;
        sum /= 3;
        int freq = 0;
        for(int i = 0; i<A.size()-1; i++){
            if(i > 0) A[i] += A[i-1];
            if(A[i] == 2*sum and freq) return 1;
            if(A[i] == sum) freq++;
        }
        return 0;
    }
};