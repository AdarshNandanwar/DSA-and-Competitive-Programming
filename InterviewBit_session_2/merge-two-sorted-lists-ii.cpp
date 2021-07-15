// https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/

void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size(), m = B.size();
    A.resize(n+m);

    int p1 = n-1, p2 = m-1, p3 = n+m-1;
    while(p1>=0 and p2>=0){
        if(A[p1] >= B[p2]){
            A[p1+p2+1] = A[p1];
            p1--;
        } else {
            A[p1+p2+1] = B[p2];
            p2--;
        }
    }
    while(p1>=0){
        A[p1+p2+1] = A[p1];
        p1--;
    }
    while(p2>=0){
        A[p1+p2+1] = B[p2];
        p2--;
    }
}
