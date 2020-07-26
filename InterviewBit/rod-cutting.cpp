// https://www.interviewbit.com/problems/rod-cutting/

// Partially Correct:

typedef long long int ll;
 
void buildVector(vector<ll> & cut, vector<vector<ll>> dp, vector<vector<ll>> & minPos, ll i, ll j, vector<int> & ans, bool & done, ll & sz){
    if(done or ans.size() == sz){
        done = 1;
        return;
    }
    if(i+1>=j) return;
    
    ll k = minPos[i][j];
    ans.push_back(cut[k]);
    buildVector(cut, dp, minPos, i, k, ans, done, sz);
    buildVector(cut, dp, minPos, k, j, ans, done, sz);
}
 
vector<int> Solution::rodCut(int A, vector<int> &B) {
    
    vector<ll> cut;
    cut.push_back(0);
    cut.insert(cut.end(), B.begin(), B.end());
    cut.push_back(A);
    ll n = cut.size(), nb = B.size();
    
    // dp[i][j] = cost of cutting the rod [cut[i]..cut[j]]
    vector<vector<ll>> dp(n, vector<ll>(n, INT_MAX));
    vector<vector<ll>> minPos(n, vector<ll>(n));
    
    // base case 
    for(ll i = 0; i<n; i++){
        dp[i][i] = 0;
        if(i+1<n) dp[i][i+1] = 0;
    }
    
    
    for(ll i = n-1; i>=0; i--){
        for(ll j = i; j<n; j++){
            for(ll k = i+1; k<j; k++){
                if(dp[i][j] > dp[i][k]+dp[k][j]+cut[j]-cut[i]){
                    dp[i][j] = dp[i][k]+dp[k][j]+cut[j]-cut[i];
                    minPos[i][j] = k;
                }
            }
        }
    }
    ll minCost = dp[0][n-1];
    bool done = 0;
    vector<int> ans;
    buildVector(cut, dp, minPos, 0, n-1, ans, done, nb);
    return ans;
}

// TLE

pair<int, vector<int>> helper(vector<int> &B, int st, int end, int leftEdge, int rightEdge){
    if(st > end) return {0, {}}; 
    pair<int, vector<int>> res = {INT_MAX, {}};
    for(int i = st; i<=end; i++){
        auto l = helper(B, st, i-1, leftEdge, B[i]);
        auto r = helper(B, i+1, end, B[i], rightEdge);
        if(res.first > l.first+r.first+rightEdge-leftEdge){
            vector<int> v;
            v.push_back(B[i]);
            v.insert(v.end(), l.second.begin(), l.second.end());
            v.insert(v.end(), r.second.begin(), r.second.end());
            res = {l.first+r.first+rightEdge-leftEdge, v};
        }
    }
    return res;
}

vector<int> Solution::rodCut(int A, vector<int> &B) {
    sort(B.begin(), B.end());
    int n = B.size();
    pair<int, vector<int>> ans = helper(B, 0, n-1, 0, A);
    return ans.second;
}

// TLE

void helper(int & A, vector<int> &B, set<int> & cut, int cost, int & minCost, vector<int> & cur, vector<int> & res){
    if(cur.size() == B.size()){
        if(cost < minCost){
            res = cur;
            minCost = cost;
        }
        return;
    } 
    
    for(auto i:B){
        if(cut.count(i)) continue;
        
        auto lb = cut.lower_bound(i);
        int right, left;
        if(lb == cut.end()) right = A;
        else right = *lb;
        if(lb == cut.begin()) left = 0;
        else left = *prev(lb);
        
        cut.insert(i);
        cur.push_back(i);
        helper(A, B, cut, cost+right-left, minCost, cur, res);
        cur.pop_back();
        cut.erase(i);
    }
}

vector<int> Solution::rodCut(int A, vector<int> &B) {
    int cost = 0, minCost = INT_MAX;
    vector<int> cur, res;
    set<int> cut;
    helper(A, B, cut, cost, minCost, cur, res);
    return res;
}