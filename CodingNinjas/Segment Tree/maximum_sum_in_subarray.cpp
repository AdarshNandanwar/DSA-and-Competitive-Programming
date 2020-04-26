// Maximum Sum In Subarray
// Send Feedback
// You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
// Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
// Given M queries, your program must output the results of these queries.
// Input
// The first line of the input file contains the integer N.
// In the second line, N numbers follow.
// The third line contains the integer M.
// M lines follow, where line i contains 2 numbers xi and yi.
// Output
// Your program should output the results of the M queries, one 
// query per line.
// Sample Input:
// 3 
// -1 2 3 
// 1
// 1 2
// Sample Output:
// 2

#include<bits/stdc++.h>
using namespace std;

struct node {
    int msum;
    int sum;
    int ssum;
    int psum;
};

void build_tree(int * arr, node * tree, int tree_node, int start, int end){
    if(start == end){
        tree[tree_node].sum = arr[start];
        tree[tree_node].msum = arr[start];
        tree[tree_node].psum = arr[start];
        tree[tree_node].ssum = arr[start];
        return;
    }
    int mid = (start+end)/2;
    build_tree(arr, tree, 2*tree_node, start, mid);
    build_tree(arr, tree, 2*tree_node+1, mid+1, end);
    node node1 = tree[2*tree_node], node2 = tree[2*tree_node+1];
    tree[tree_node].sum = node1.sum + node2.sum;
    tree[tree_node].psum = max(node1.psum, node1.sum+node2.psum);
    tree[tree_node].ssum = max(node2.ssum, node1.ssum+node2.sum);
    tree[tree_node].msum = max(node1.msum, max(node2.msum, node1.ssum+node2.psum));
    return;
}

node query(node * tree, int tree_node, int start, int end, int left, int right){
    if(right < start || left > end){
        return {-100000, -100000, -100000, -100000};
    } else if(start >= left && end <= right){
        return tree[tree_node];
    } else {
        int mid = (start+end)/2;
        node node1 = query(tree, 2*tree_node, start, mid, left, right);
        node node2 = query(tree, 2*tree_node+1, mid+1, end, left, right);
        node ans;
        ans.sum = node1.sum + node2.sum;
        ans.psum = max(node1.psum, node1.sum+node2.psum);
        ans.ssum = max(node2.ssum, node1.ssum+node2.sum);
        ans.msum = max(node1.msum, max(node2.msum, node1.ssum+node2.psum));
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
        cin>>x>>y;
        node ans = query(tree, 1, 0, n-1, x-1, y-1);
        cout<<ans.msum<<endl;
    }
    delete [] arr;
    delete [] tree;
    return 0;
}