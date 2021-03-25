// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    if(n == 0) return 0;
    int p1 = 0, p2 = 0;
    
    while(p2<n){
        while(p2<n and A[p1] == A[p2]) p2++;
        if(p2<n){
            p1++;
            swap(A[p1], A[p2]);
            p2++;
        }
    }
    while(A.size() > p1+1) A.pop_back();
    return p1+1;
}
