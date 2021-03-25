// https://www.interviewbit.com/problems/maxspprod/

// Method 1 (Stack, O(n)):

#define MOD 1000000007
typedef long long ll;
int Solution::maxSpecialProduct(vector<int> &A) {
    ll res = 0, n = A.size();
    vector<ll> prevGr(n, -1), nextGr(n, -1);
    stack<ll> st;
    for(ll i = n-1; i>=0; i--){
        while(!st.empty() and A[st.top()]<A[i]){
            prevGr[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(ll i = 0; i<n; i++){
        while(!st.empty() and A[st.top()]<A[i]){
            nextGr[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    for(ll i = 0; i<n; i++){
        if(prevGr[i] != -1 and nextGr[i] != -1){
            res = max(res, prevGr[i]*nextGr[i]);
        }
    }
    return res%MOD;
}
