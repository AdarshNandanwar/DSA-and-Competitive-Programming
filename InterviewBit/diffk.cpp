// https://www.interviewbit.com/problems/diffk/

int Solution::diffPossible(vector<int> &A, int B) {
    int n = A.size();
    int p1 = 0, p2 = 0;
    while(p2<n){
        if(p1 == p2){ 
            p2++;
        }else if(A[p2]-A[p1] == B){
            return 1;
        } else if(A[p2]-A[p1] > B){
            p1++;
        } else {
            p2++;
        }
    }
    return 0;
}
