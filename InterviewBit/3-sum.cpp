// https://www.interviewbit.com/problems/3-sum/

// Method 1 (2 Pointers, O(n)):

int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    long n = A.size(), res = B, j, k, closestSum = INT_MAX, sum;
    for(long i = 0; i<n-2; i++){
        j = i+1, k = n-1;
        while(j<k){
            sum = (long)A[i]+(long)A[j]+(long)A[k];
            if(closestSum > abs(B-sum)){
                closestSum = abs(B-sum);
                res = sum;
            } 
            if(sum > B){
                k--;
            } else {
                j++;
            }
        }
    }
    return res;
}
