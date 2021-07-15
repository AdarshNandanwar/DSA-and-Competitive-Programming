// https://www.hackerrank.com/contests/placements-2021-mock-1/challenges/kartiks-way-out

// Kartik got stuck in a maze which had a structure of a tree. The maze contains  rooms and Kartik is stuck at the root of the tree which is room . He will be able to escape the maze if he’s able to reach any of the rooms situated at the leaves of the tree. He cannot visit rooms he has already visited.

// However, some of the rooms contain a trap and Kartik will get lost in the maze forever if he visits more than  such rooms consecutively. Lucky for him, he already knows which rooms contain a trap and which don’t.

// Your task is to help Kartik count the number of paths he can take to get out of the maze.

// Note that a tree is an undirected graph with no cycles in it.

// Input Format

// Each test case consists of  lines, where each line is described below

 

   

 

 


 

// : number of rooms in the maze

// : maximum number of consecutive traps Kartik can handle without getting lost in the maze

// :  if the  room doesn’t contain a trap,  if the  room contains a trap

// , : denotes there is a path from room  to 

// It is guaranteed that the structure of the maze described in the input would correspond to a tree rooted at 1.

// Constraints



//  can only be  or 


// Output Format

// Print the number of distinct paths Kartik can take to get out of the maze successfully.

// Sample Input 0

// 2 1
// 0 1
// 1 2
// Sample Output 0

// 1
// Explanation 0

// The graph consists of 2 nodes, and Kartik is allowed to visit at max 1 trap node.

// Node 1 does not have a trap, whereas node 2 does.

// The graph has only 1 path from Node 1 (root) to Node 2 (leaf) and Kartik can take that path.

// Sample Input 1

// 2 1
// 1 1
// 1 2
// Sample Output 1

// 0
// Explanation 1

// Same graph structure as above, but both nodes are trap and Kartik is allowed to visit only 1. Hence no path exists from root to leaf.

// Sample Input 2

// 5 2
// 1 0 1 0 1
// 1 2
// 1 3
// 2 4
// 2 5
// Sample Output 2

// 3

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void dfs(ll cur, vector<ll> & trap, vector<vector<ll>> & nbr, ll remaining, ll & res, vector<bool> & visited, const ll & k){
    visited[cur] = 1;
    ll next_remaining = trap[cur] ? remaining-1 : k;
    if(next_remaining < 0) return;
    ll nbr_count = 0;
    for(auto nb:nbr[cur]){
        if(visited[nb]) continue;
        nbr_count++;
        dfs(nb, trap, nbr, next_remaining, res, visited, k);
    }
    if(nbr_count == 0){
        res++;
    }
}

ll n;

void solve(){

    ll k;
    cin>>n>>k;
    vector<ll> trap(n);
    vector<bool> visited(n, 0);
    for(auto &i:trap) cin>>i;
    vector<vector<ll>> nbr(n, vector<ll>(0));
    for(int i = 0; i<n-1; i++){
        ll a, b;
        cin>>a>>b;
        a--;
        b--;
        nbr[a].push_back(b);
        nbr[b].push_back(a);
    }
    ll res = 0;
    dfs(0, trap, nbr, k, res, visited, k);
    cout<<res<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    while(t--){
        solve();
    }
    return 0;
}