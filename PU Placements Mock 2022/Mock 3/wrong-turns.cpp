// https://www.hackerrank.com/contests/placements-2021-mock-3/challenges/wrong-turns

/*

An array of N distinct integers is given in such a manner that a Binary Search Tree is to be formed by BST insertion of elements in the order.

An intern who has just learnt searching in a BST is trying to search a value in the tree.

As he has just learnt searching, we know he'll make a mistake at atmost 1 point during the searching. Meaning, atmost at one node from root to the correct destination, he'll take the opposite turn instead (he'll either go left if he's supposed to go right, or vice versa), and after this wrong turn he'll go correctly (as he's supposed to go) on every node, and if he has made a wrong turn, he'll eventually end up at some wrong node.

For Q queries of the search value (search value is guaranteed to be a node in the tree), find the Expected Value of node he ends up reaching.

Formula for Expected Value:

where  is the value of an event, and  is the probability of occurence of that particular event.
The intern can take a wrong turn only at a node where it is possible, i.e. he cannot take a wrong turn if the other child (where he is NOT supposed to go) is NULL.

During the searching procedure, he has equal probability of taking the wrong turn at every node in the search path (wherever he CAN possibly take the wrong turn), or not take the wrong turn at all.

Input Format

The first line contains two space separated integers, N Q denoting the number of elements in the array and number of queries, respectively.
The next line contains N integers, denoting elements of the array.
The next Q lines contain one integer each, denoting the search keys.

Constraints

For all test cases:

1 <= Q <= 3*105
0 <= Ai <= 106
Search key is guaranteed to be a valid value in the formed BST.
All keys in the BST will be distinct
For 5 points:

1 <= N <= 1000
For 3 points:

1 <= N <= 105
Height of tree <= 210
For last 2 points:

1 <= N <= 105
Height of tree <= N (no limitation on balance of BST formed)
Output Format

Print the expected value of the node that the intern will end at, on a new line for each query.

Your answer will be considered correct, if the absolute error is less than 10-4

Sample Input 0

11 6
7 4 10 2 6 8 12 3 5 9 11
7
4
10
5
6
8
Sample Output 0

7.000000
6.000000
8.000000
5.333333
5.666667
8.333333
Explanation 0

The tree formed will be as follows -

Image of the Binary Tree formed, also uploaded on Moodle.

Explanation for Queries:

For search 7, we have to go to the root and can't take any wrong turn, therefore expected value is 7.

For search key 5, the correct path is 7 -> 4 -> 6 -> 5.

If he takes the wrong turn at 7 itself, he'll end up at 8.
If he takes the wrong turn at 4, he'll end up at 3.
He cannot take a wrong turn at 6, because the other child is NULL.
If he doesn't take the wrong turn, he ends up at 5 itself.
All these 3 cases (wrong turn at 7, wrong turn at 4 and no wrong turn) have equal probability of 1/3.
Do not consider sequential probability (if you aren't aware of this term, ignore the point.)
Therefore, the final expected value will be 8*(1/3) + 3*(1/3) + 5*(1/3) = 5.3333

*/

// Method 1 (WA):

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

struct bst{
    bst * left, * right;
    ll val;
    bst(int val): val(val), left(NULL), right(NULL) {};
};

bst * insert(bst * root, ll val){
    if(root == NULL) {
        return new bst(val);
    }
    if(root->val < val){
        root->right = insert(root->right, val);
    } else {
        root->left = insert(root->left, val);
    }
    return root;
}

// {sum, count}
pair<ll, ll> helper(bst * root, ll val, bool done, unordered_map<bst *, unordered_map<ll>> & dp){
    if(root->val == val) return {val, 1};
    if(dp[root].count(val))
    if(root->left){
        if(root->right){
            if(done){
                if(root->val < val){
                    return helper(root->right, val, done, dp);
                } else {
                    return helper(root->left, val, done, dp);
                }
            } else {
                if(root->val < val){
                    auto hl = helper(root->left, val, 1, dp);
                    auto hr = helper(root->right, val, 0, dp);
                    return {hl.first+hr.first, hl.second+hr.second};
                } else {
                    auto hl = helper(root->left, val, 0, dp);
                    auto hr = helper(root->right, val, 1, dp);
                    return {hl.first+hr.first, hl.second+hr.second};
                }
            }
        } else {
            if(root->val < val){
                return {root->val, 1};
            } else {
                return helper(root->left, val, done, dp);
            }
        }
    } else {
        if(root->right){
            if(root->val < val){
                return helper(root->right, val, done, dp);
            } else {
                return {root->val, 1};
            }
        } else {
            return {root->val, 1};
        }
    }
}

void solve(){

    ll m, val;
    cin>>n>>m;
    bst * root = NULL;

    for(int i = 0; i<n; i++){
        cin>>val;
        root = insert(root, val);
    }

    unordered_map<bst *, unordered_map<unordered_map<ll>, pair<ll, ll>>> dp;

    for(int i = 0; i<m; i++){
        cin>>val;
        auto h = helper(root, val, 0, dp);
        cout<<(double)h.first/h.second<<endl;
    }

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

// Solution:

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct Node{
    int val;
    Node* left;
    Node* right;
    int highest;
    int lowest;
    double expectation;
    Node(int x){
        val=x;
        lowest=x;
        highest=x;
        left=NULL;
        right=NULL;
        expectation=0;
    }  
};
Node* insert(Node* root,int val){
    if(!root)
        return new Node(val);
    if(val>root->val){
        root->highest=max(root->highest,val);
        root->right=insert(root->right,val);
    }
    else{
        root->lowest=min(root->lowest,val);
        root->left=insert(root->left,val);
    }
    return root;
}
void preorder(Node* root,lli wrongSum,lli wrongTurns,unordered_map<int,double> &hash){
    if(!root)
        return;
    root->expectation=((double)wrongSum+root->val)/(wrongTurns+1);
    hash[root->val]=root->expectation;
    if(root->right)
        preorder(root->left,wrongSum+root->right->lowest,wrongTurns+1,hash);
    else
        preorder(root->left,wrongSum,wrongTurns,hash);
    if(root->left)
        preorder(root->right,wrongSum+root->left->highest,wrongTurns+1,hash);
    else
        preorder(root->right,wrongSum,wrongTurns,hash);
    return;
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q,a;
    cin >> n >> q;
    Node* root=NULL;
    for(int i=0;i<n;i++){
        cin >> a;
        root=insert(root,a);
    }
    unordered_map<int,double> hash;
    preorder(root,0,0,hash);
    for(int i=0;i<q;i++){
        cin >> a;
        cout << fixed << setprecision(6) << hash[a] << "\n";
    }
    return 0;
}