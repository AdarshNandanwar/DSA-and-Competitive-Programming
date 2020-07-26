// https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int na = A.size(), nb = B.size();

        // binary search on the number of elements int he first hafl of A
        // [lo..mid-1] and [mid..hi];

        // lo and hi set to ensure that midB is in [0, nb]
        int lo = max(0, (na-nb)/2), hi = min(na, (na+nb)/2), midA, midB;
        while(lo<=hi){

            midA = lo + (hi-lo)/2;
            midB = (na+nb)/2 - midA;
            
            if((midA==0 or midB==nb or A[midA-1] <= B[midB]) and (midB==0 or midA==na or B[midB-1] <= A[midA])){
                // found
                if((na+nb)%2){
                    return min((midA>=0 and midA<na)?A[midA]:INT_MAX,
                                (midB>=0 and midB<nb)?B[midB]:INT_MAX);
                } else {
                    return (max((midA-1>=0 and midA-1<na)?A[midA-1]:INT_MIN, (midB-1>=0 and midB-1<nb)?B[midB-1]:INT_MIN)
                            +min((midA>=0 and midA<na)?A[midA]:INT_MAX, (midB>=0 and midB<nb)?B[midB]:INT_MAX))/((double)2);
                }
            } else if((midA-1>=0 and midB<nb and A[midA-1] > B[midB])){
                // shift partition A towards left
                hi = midA-1;
            } else {
                // shift partition A towards right
                lo = midA+1;
            }
        }
        return 0;
    }
};