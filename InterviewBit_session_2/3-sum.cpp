// https://www.interviewbit.com/problems/3-sum/

// Method 1 (2 Pointer):

int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int res = INT_MAX, diff = INT_MAX, n = A.size();
    for(int i = 0; i<n-2; i++){
        int p1 = i+1, p2 = n-1;
        while(p1<p2){
            if(diff > abs(B-(A[i]+A[p1]+A[p2]))){
                diff = abs(B-(A[i]+A[p1]+A[p2]));
                res = A[i]+A[p1]+A[p2];
            }
            if(A[i]+A[p1]+A[p2] < B) p1++;
            else if(A[i]+A[p1]+A[p2] > B) p2--;
            else return B;
        }
    }
    return res;
}
