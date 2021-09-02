// https://www.interviewbit.com/problems/n3-repeat-number/

// Method 1 (Boyer–Moore majority vote algorithm, O(n) time, O(1) space):

int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    // Boyer–Moore majority vote algorithm

    int c1 = 0, c2 = 0, v1 = -1, v2 = -1, n = A.size();
    for(int i = 0; i<n; i++){
        if(A[i] == v1){
            c1++;
        } else if(A[i] == v2){
            c2++;
        } else if(c1 == 0){
            v1 = A[i];
            c1++;
        } else if(c2 == 0){
            v2 = A[i];
            c2++;
        } else {
            c1--;
            c2--;
        }
    }

    c1 = c2 = 0;
    for(auto & i:A){
        c1 += (i == v1);
        c2 += (i == v2);
    }
    if(c1 > n/3) return v1;
    if(c2 > n/3) return v2;
    return -1;
}
