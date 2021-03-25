// https://www.interviewbit.com/problems/delete-edge/

// Method 1 (DFS)

#define MOD 1000000007
typedef long long ll;

ll getSum(vector<int> &A, vector<vector<ll>> &adjList, ll cur, ll prev){
    ll res = A[cur];
    for(auto child:adjList[cur]){
        if(child == prev) continue;
        res += getSum(A, adjList, child, cur);
    }
    return res;
}
void helper(vector<int> &A, vector<vector<ll>> &adjList, ll cur, ll prev, ll & sum, ll & ans){
    for(auto child:adjList[cur]){
        if(child == prev) continue;
        long h = getSum(A, adjList, child, cur);
        ans = max(ans, (h*(sum-h))%MOD);
        helper(A, adjList, child, cur, sum, ans);
    }
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    ll n = A.size();
    vector<vector<ll>> adjList(n);
    for(auto i:B){
        adjList[i[0]-1].push_back(i[1]-1);
        adjList[i[1]-1].push_back(i[0]-1);
    }
    ll sum = getSum(A, adjList, 0, -1), ans = INT_MIN;
    helper(A, adjList, 0, -1, sum, ans);
    return ans;
}
