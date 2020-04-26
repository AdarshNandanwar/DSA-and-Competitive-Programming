// Counting Even/Odd
// Send Feedback
// Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:-
// Query 0 :- modify the element present at index i to x.
// Query 1:- count the number of even numbers in range l to r inclusive.
// Query 2:- count the number of odd numbers in range l to r inclusive.
// Input:
// First line of the input contains the number N. Next line contains N natural numbers. 
// Next line contains an integer Q followed by Q queries.

// 0 x y - modify the number at index x to y. 

// 1 x y - count the number of even numbers in range l to r inclusive.

// 2 x y - count the number of odd numbers in range l to r inclusive.
// Constraints:
// 1<=N,Q<=10^5

// 1<=l<=r<=N 

// 0<=Ai<=10^9

// 1<=x<=N

// 0<=y<=10^9
// Note:-
// indexing starts from 1.
// Sample Input
// 6
// 1 2 3 4 5 6
// 4
// 1 2 5
// 2 1 4
// 0 5 4
// 1 1 6
// Sample Output
// 2
// 2
// 4

#include<bits/stdc++.h>
using namespace std;

void build_tree(int * arr, int * tree, int tree_node, int start, int end){
    if(start == end){
        if(arr[start]%2 == 0)
            tree[tree_node] = 1;
        else
            tree[tree_node] = 0;
        return;
    }
    int mid = (start+end)/2;
    build_tree(arr, tree, 2*tree_node, start, mid);
    build_tree(arr, tree, 2*tree_node+1, mid+1, end);
    tree[tree_node] = tree[2*tree_node]+tree[2*tree_node+1];
    return;
}

void update_tree(int * arr, int * tree, int tree_node, int start, int end, int index, int value){
    if(start == end){
        arr[start] = value;
        if(value%2 == 0)
            tree[tree_node] = 1;
        else
            tree[tree_node] = 0;
        return;
    }
    int mid = (start+end)/2;
    if(index <= mid){
        update_tree(arr, tree, 2*tree_node, start, mid, index, value);        
    } else {
        update_tree(arr, tree, 2*tree_node+1, mid+1, end, index, value);
    }
    tree[tree_node] = tree[2*tree_node]+tree[2*tree_node+1];
    return;
}

int even_tree(int * tree, int tree_node, int start, int end, int left, int right){
    if(left > end || right < start){
        return 0;
    }
    if(left <= start && end <= right){
        return tree[tree_node];
    }
    int mid = (start+end)/2, ans = 0;
    ans += even_tree(tree, 2*tree_node, start, mid, left, right);
    ans += even_tree(tree, 2*tree_node+1, mid+1, end, left, right);
    return ans;
}

int main() {

	// Write your code here
    int n;
    cin>>n;
    int * arr = new int[n];
    int * tree = new int[4*n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    build_tree(arr, tree, 1, 0, n-1);
    int q, type, x, y;
    cin>>q;
    while(q--){
        cin>>type>>x>>y;
        if(type == 0){
            update_tree(arr, tree, 1, 0, n-1, x-1, y);
        } else if(type == 1){
            cout<<even_tree(tree, 1, 0, n-1, x-1, y-1)<<endl;
        } else{
            cout<<y-x+1-even_tree(tree, 1, 0, n-1, x-1, y-1)<<endl;
        }
    }
    return 0;
}