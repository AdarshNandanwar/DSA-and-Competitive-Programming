// https://www.interviewbit.com/problems/distribute-candy/

// Method 1 (Greedy, O(n)):

int Solution::candy(vector<int> &A) {
    int n = A.size(), res = 0;
    vector<int> distLeft(n, 1), distRight(n, 1);
    for(int i = 1; i<n; i++){
        if(A[i]>A[i-1]) distLeft[i] = distLeft[i-1]+1;
        else distLeft[i] = 1;
    }
    for(int i = n-2; i>=0; i--){
        if(A[i]>A[i+1]) distRight[i] = distRight[i+1]+1;
        else distRight[i] = 1;
    }
    for(int i = 0; i<n; i++) res += max(distLeft[i], distRight[i]);
    return res;
}
