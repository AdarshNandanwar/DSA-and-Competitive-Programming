// Question:

// Min Jumps
// You are given an array of N integers, A1, A2 ,…, AN and an integer B which denotes that from any index i, you can jump to any of the indices i+1, i+2, …, i+B. Also, if you step on index i, you have to pay Ai coins. If Ai is -1, it means you can’t land on index i.

// You start from index 1, and your aim is to reach index N. Return the path you should take to minimise the number of coins required. If there are multiple paths with same cost, return the lexicographically smallest such path. If its not possible to reach index N return empty array.

// Notes

// Ai is either > 0(denoting cost) or -1(denoting that it is not possible to land on index i).
// You have to pay coins both at starting and ending indices.
// Path a1, a2 ,…, an is lexicographically smaller than b1, b2 ,…, bm, if and only if at the first i where ai and bi differ, ai < bi, or if no such i exists, then n < m.
// For example,

// A=[1, 2, 4, -1, 2] and B = 2

// The path which requires minimum coins is to start at index 1 and then move to index 3 and then to 5.
// So return [1, 3, 5].

// Another example,

// A=[1, 2, 4, -1, 2] and B = 1

// In this case it is not possible to reach index 5. So return empty array [].


// Extra Test Cases:

// IP:
// 29 923 945 725 587 995 940 746 867 95 708 46 818 280 675 621 16 158 599 5 688 963 960 870 805 973 247 370 759 -1
// 29
// OP:

// IP:
// 5 1 2 4 -1 2
// 2
// OP: 
// 1 3 5




// Attempt 2 (TLE):

vector<int> Solution::minJumps(vector<int> &A, int B) {
    vector<int> ans;
    int n = A.size();
    if(n == 0 or A[0] == -1) return ans;
    vector<pair<int, int>> dp(n, make_pair(INT_MAX, -1));
    // dp[i] = {min cost to arrive at index i, prev index}
    dp[0] = make_pair(A[0], -1);
    for(int i = 1; i<n; i++){
        if(A[i] != -1){
            for(int j = 1; j<=B and i-j>=0; j++){
                if(A[i-j] != -1 and dp[i].first >= dp[i-j].first+A[i]) dp[i] = make_pair(dp[i-j].first+A[i], i-j);
            }
        }
    }
    // reconstruct path
    int cur = n-1;
    while(cur != -1){
        ans.push_back(cur+1);
        cur = dp[cur].second;
    }
    if(ans.size() and ans.back() == 1){
        reverse(ans.begin(), ans.end());
        return ans;
    } else return {};
}

// Attempt 1 (TLE):

void helper(vector<int> &A, int B, int index, int curCost, int & minCost, vector<int> & cur, vector<int> & ans, vector<int> & dp){
    int n = A.size();
    if(index>=n or A[index] == -1 or curCost >= minCost) return;
    if(index == n-1){
        if(curCost < minCost){
            minCost = curCost;
            ans.clear();
            for(auto i:cur) ans.push_back(i+1);
        }
        return;
    }
    if(dp[index] <= curCost) return;
    for(int i = 1; i<=B; i++){
        cur.push_back(index+i);
        helper(A, B, index+i, curCost+A[index+i], minCost, cur, ans, dp);
        cur.pop_back();
    } 
    dp[index] = min(dp[index], curCost);
}

vector<int> Solution::minJumps(vector<int> &A, int B) {
    int n = A.size();
    vector<int> ans, cur;
    if(n == 0) return ans;
    vector<int> dp(n, INT_MAX);
    int curCost = A[0], minCost = INT_MAX;
    cur.push_back(0);
    helper(A, B, 0, curCost, minCost, cur, ans, dp);
    return ans;
}
