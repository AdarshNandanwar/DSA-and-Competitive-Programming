// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/

// Method 1 (2 pointers, O(n)):

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    if(n <= 2) return A.size();
    int p1 = 2, p2 = 2, prevPrev = A[0], prev = A[1];
    while(p2<n){
        if(prevPrev != A[p2]) {
            A[p1] = A[p2];
            p1++;
        }
        prevPrev = prev;
        prev = A[p2];
        p2++;
    }
    for(int i = 0; i<n-p1; i++) A.pop_back();
    return p1;
}