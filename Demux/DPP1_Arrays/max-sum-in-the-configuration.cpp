/*You are required to complete this method*/
int max_sum(int A[],int N)
{
//Your code here

    int ans, maxAns = INT_MIN, sum = 0;
    
    for(int i =0; i<N; i++){
        sum+=A[i];
        ans += (i*A[i]);
    }
    maxAns = max(ans, maxAns);
    
    for(int i = N-1; i>=1; i--){
        ans = ans + (sum-A[i]) - (A[i]*(N-1));
        maxAns = max(maxAns, ans);
    }
    return maxAns;
}