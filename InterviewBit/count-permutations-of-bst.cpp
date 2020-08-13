// https://www.interviewbit.com/problems/count-permutations-of-bst/

// Method (DP, Maths, O(n*m)):

#define MOD 1000000007
typedef long long int ll;

vector<ll> fact(51, -1);
ll getFact(ll n){
    if(n <= 1) return fact[n] = 1;
    if(fact[n] != -1) return fact[n];
    return fact[n] = (n*getFact(n-1))%MOD;
}

ll helper(ll n, ll reqHeight, vector<vector<ll>> & dp){
    if(reqHeight == -1) return n == 0;
    if(reqHeight == 0) return dp[n][reqHeight] = (n == 1);
    if(dp[n][reqHeight] != -1) return dp[n][reqHeight];
    ll res = 0;
    // i = number of nodes in left subtree
    for(int i = 0; i<n; i++){
        // temp = number of structures of height reqHeight with i elements in left subtree
        int temp = 0;
        
        // fix left subtree height to reqHeight-1
        for(int j = -1; j<reqHeight-1; j++){
            temp = (temp+(helper(i, reqHeight-1, dp)*helper(n-1-i, j, dp))%MOD)%MOD;
        }
        // fix right subtree height to reqHeight-1
        for(int j = -1; j<reqHeight-1; j++){
            temp = (temp+(helper(i, j, dp)*helper(n-1-i, reqHeight-1, dp))%MOD)%MOD;
        }
        // fix both subtree height to reqHeight-1
        temp = (temp+(helper(i, reqHeight-1, dp)*helper(n-1-i, reqHeight-1, dp))%MOD)%MOD;
    
        // if seq1 gives left subtree and seq2 gives right subtree
        // number of ways to merge the 2 seq preserving their order
        // is equal to selecting len1 spots from (len1+len2) spots
        // = (len1+len2)C(len1)
        
        ll C = 1, len1 = i, len2 = n-1-i;
        if(len1 < len2) swap(len1, len2);
        for(int i = len1+1; i<=len1+len2; i++) C = C*i;
        C = (C/getFact(len2))%MOD;
        
        res = (res + (temp*C)%MOD)%MOD;
        
    }
    return dp[n][reqHeight] = res;
}

int Solution::cntPermBST(int A, int B) {
    vector<vector<ll>> dp(A+1, vector<ll>(B+1, -1));
    auto res = helper(A, B, dp);
    return res;
}
