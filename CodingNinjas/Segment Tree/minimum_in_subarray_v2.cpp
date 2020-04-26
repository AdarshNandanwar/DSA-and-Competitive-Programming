// Minimum In SubArray
// Send Feedback
// Range Minimum Query
// Given an array A of size N, there are two types of queries on this array.
// 1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
// 2) u x y: In this query you need to update A[x]=y.
// Input:
// First line of the test case contains two integers, N and Q, size of array A and number of queries.
// Second line contains N space separated integers, elements of A.
// Next Q lines contain one of the two queries.
// Output:
// For each type 1 query, print the minimum element in the sub-array A[l:r].
// Contraints:
// 1≤N,Q,y≤10^5
// 1≤l,r,x≤N
// Sample Input :
// 5 5
// 1 5 2 4 3
// q 1 5
// q 1 3
// q 3 5
// u 3 6
// q 1 5
// Sample Output :
// 1
// 1
// 2
// 1

#include<bits/stdc++.h>
using namespace std;

void create_tree(int * arr, int n, int * tree, int tree_node, int start, int end){
    if(start == end){
        tree[tree_node] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    create_tree(arr, n, tree, 2*tree_node, start, mid);
    create_tree(arr, n, tree, 2*tree_node+1, mid+1, end);
    tree[tree_node] = min(tree[2*tree_node], tree[2*tree_node+1]);
    return;
}

int min_in_subarray_1(int * tree, int tree_node, int start, int end, int left, int right){
    if(left > end || right < start){
        return INT_MAX;
    } else if(start >= left && right >= end){
        return tree[tree_node];
    } else {
        int mid = (start+end)/2;
        int option1 = min_in_subarray_1(tree, 2*tree_node, start, mid, left, right);
        int option2 = min_in_subarray_1(tree, 2*tree_node+1, mid+1, end, left, right);
        return min(option1, option2);
    }
}

void update_tree(int * tree, int tree_node, int start, int end, int index, int value){
    if(start == end){
        tree[tree_node] = value;
        return;
    }
    int mid = (start+end)/2;
    if(mid >= index){
        update_tree(tree, 2*tree_node, start, mid, index, value);
    } else {
        update_tree(tree, 2*tree_node+1, mid+1, end, index, value);
    }
    tree[tree_node] = min(tree[2*tree_node], tree[2*tree_node+1]);
    return;
}

int main() {
	int n, q, x, y;
    char c;
    cin>>n>>q;
    int * arr = new int[n];
    int * tree = new int[4*n]();
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    create_tree(arr, n, tree, 1, 0, n-1);
    while(q--){
        cin>>c>>x>>y;
        if(c == 'q'){
            cout<<min_in_subarray_1(tree, 1, 0, n-1, x-1, y-1)<<endl;
        } else {
            update_tree(tree, 1, 0, n-1, x-1, y);
        }
    }    
    delete [] arr;
    delete [] tree;
    return 0;
}