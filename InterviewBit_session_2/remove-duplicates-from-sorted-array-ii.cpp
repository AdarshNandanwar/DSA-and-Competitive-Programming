// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    if(n == 0) return 0;
    int p1 = 0, p2 = 0, k = 2;
    while(p2<n){
        int val = A[p2];
        while(p2<n and val == A[p2]){
            if(k>0) A[p1++] = val;
            p2++;
            k--;
        }
        k = 2;
    }
    return p1;
}
