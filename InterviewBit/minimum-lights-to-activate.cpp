// https://www.interviewbit.com/problems/minimum-lights-to-activate/

typedef long long ll;

int Solution::solve(vector<int> &A, int B) {
    ll n = A.size();
    vector<ll> rightRange(n, 0);
    for(ll i = 0; i<n; i++){
        if(A[i]) rightRange[max(0ll, i-B+1)] = max(rightRange[max(0ll, i-B+1)], i+B-1);
    }
    ll curEnd = 0, childEnd = 0, cur = 0, count = 0;
    while(cur<n){
        while(cur<=curEnd){
            childEnd = max(childEnd, cur+rightRange[cur]);
            cur++;
        }
        if(curEnd>=n-1) return count;
        if(curEnd == childEnd) return -1;
        curEnd = childEnd;
        count++;
    }
    return -1;
}
