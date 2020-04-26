// Maximum Pair Sum
// Send Feedback
// You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
// Update:
// This will be indicated in the input by a 'U' followed by space and then two integers i and x.
// U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
// This operation sets the value of A[i] to x.
// Query:
// This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
// Q x y, 1 ≤ x < y ≤ N.
// You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
// Input
// The first line of input consists of an integer N representing the length of the sequence. 
// Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q lines contain the operations.
// Output
//  Output the maximum sum mentioned above, in a separate line, for each Query.
// Input:
// 5
// 1 2 3 4 5
// 6
// Q 2 4
// Q 2 5
// U 1 6
// Q 1 5
// U 1 7
// Q 1 5
// Output:
// 7
// 9
// 11
// 12

#include<bits/stdc++.h>
using namespace std;

struct node {
    int maximum;
    int smaximum;
};

void build_tree(int * arr, node * tree, int tree_node, int start, int end){
    if(start == end){
        tree[tree_node].maximum = arr[start];
        tree[tree_node].smaximum = INT_MIN;
        return;
    }
    int mid = (start+end)/2;
    build_tree(arr, tree, 2*tree_node, start, mid);
    build_tree(arr, tree, 2*tree_node+1, mid+1, end);
    tree[tree_node].maximum = max(tree[2*tree_node].maximum, tree[2*tree_node+1].maximum);
    tree[tree_node].smaximum = min(max(tree[2*tree_node].maximum, tree[2*tree_node+1].smaximum), max(tree[2*tree_node+1].maximum, tree[2*tree_node].smaximum));
    return;
}

void update_tree(int * arr, node * tree, int tree_node, int start, int end, int index, int value){
    if(start == end){
        arr[start] = value;
        tree[tree_node].maximum = value;
        return;
    }
    int mid = (start+end)/2;
    if(index <= mid){
        update_tree(arr, tree, 2*tree_node, start, mid, index, value);
    } else {
        update_tree(arr, tree, 2*tree_node+1, mid+1, end, index, value);
    }
    tree[tree_node].maximum = max(tree[2*tree_node].maximum, tree[2*tree_node+1].maximum);
    tree[tree_node].smaximum = min(max(tree[2*tree_node].maximum, tree[2*tree_node+1].smaximum), max(tree[2*tree_node+1].maximum, tree[2*tree_node].smaximum));
    return;
}

node query(node * tree, int tree_node, int start, int end, int left, int right){
    if(right < start || left > end){
        return {INT_MIN, INT_MIN};
    } else if(start >= left && end <= right){
        return tree[tree_node];
    } else {
        int mid = (start+end)/2;
        node node1 = query(tree, 2*tree_node, start, mid, left, right);
        node node2 = query(tree, 2*tree_node+1, mid+1, end, left, right);
        node ans;
        ans.maximum = max(node1.maximum, node2.maximum);
        ans.smaximum = min(max(node1.smaximum, node2.maximum), max(node1.maximum, node2.smaximum));
        return ans;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin>>n;
    int * arr = new int[n];
    node * tree = new node[4*n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    build_tree(arr, tree, 1, 0, n-1);
    cin>>q;
    while(q--){
        int x, y;
        char c;
        cin>>c>>x>>y;
        if(c == 'Q'){
            node ans = query(tree, 1, 0, n-1, x-1, y-1);
            cout<<ans.maximum+ans.smaximum<<endl;
        } else {
            update_tree(arr, tree, 1, 0, n-1, x-1, y);
        }
    }
    delete [] arr;
    delete [] tree;
    return 0;
}