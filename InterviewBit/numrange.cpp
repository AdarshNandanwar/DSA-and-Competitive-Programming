// https://www.interviewbit.com/problems/numrange/

int countLess(vector<int> &A, int B){
    int n  =A.size();
    if(n == 0) return 0;
    // inclusive
    int p1 = 0, p2 = 0, sum = A[0], count = 0;
    while(p2<n){
        while(p1<p2 and sum>B){
            sum -= A[p1];
            p1++;
        }
        if(sum <= B) count += (p2-p1+1);
        p2++;
        sum += A[p2];
    }
    return count;
}

int Solution::numRange(vector<int> &A, int B, int C) {
    return countLess(A, C)-countLess(A, B-1);
}
