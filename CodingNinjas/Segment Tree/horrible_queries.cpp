// Horrible Queries
// Send Feedback
// World is getting more evil and it's getting tougher to get into the Evil League of Evil. Since the legendary Bad Horse has retired, now you have to correctly answer the evil questions of Dr. Horrible, who has a PhD in horribleness (but not in Computer Science). You are given an array of N elements, which are initially all 0. After that you will be given C commands. They are -
// 0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.

// 1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)
// Input
// In the first line you'll be given T, number of test cases.

// Each test case will start with N (N <= 100 000) and C (C <= 100 000). After that you'll be given C commands in the format as mentioned above. 1 <= p, q <= N and 1 <= v <= 10^7.
// Output
// Print the answers of the queries.
// Input:
// 1
// 8 6
// 0 2 4 26
// 0 4 8 80
// 0 4 5 20
// 1 8 8 
// 0 5 7 14
// 1 4 8
// Output:
// 80  
// 508

#include<bits/stdc++.h>
using namespace std;

void build_tree(int * arr, int * tree, int tree_node, int start, int end){
    if(start == end){
        tree[tree_node] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    build_tree(arr, tree, 2*tree_node, start, mid);
    build_tree(arr, tree, 2*tree_node+1, mid+1, end);
    tree[tree_node] = tree[2*tree_node] + tree[2*tree_node+1];
    return;
}

void add_tree(int * tree, int tree_node, int start, int end, int left, int right, int value){
    if(start > end){
        return;
    }
    if(left > end || right < start){
        return;
    }
    if(left <= start && end <= right){
        tree[tree_node] += (end-start+1)*value;
        if(start == end){
            return;
        }
    }
    
    int mid = (start+end)/2;
    add_tree(tree, 2*tree_node, start, mid, left, right, value);
    add_tree(tree, 2*tree_node+1, mid+1, end, left, right, value);
    tree[tree_node] = tree[2*tree_node] + tree[2*tree_node+1];
    return;
}

int query(int * tree, int tree_node, int start, int end, int left, int right){
    if(right < start || left > end){
        return 0;
    } else if(start >= left && end <= right){
        return tree[tree_node];
    } else {
        int mid = (start+end)/2, ans = 0;
        ans += query(tree, 2*tree_node, start, mid, left, right);
        ans += query(tree, 2*tree_node+1, mid+1, end, left, right);
        return ans;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, t;
    cin>>t;
    while(t--){
        cin>>n>>q;
        int * arr = new int[n]();
        int * tree = new int[4*n]();
        build_tree(arr, tree, 1, 0, n-1);
        while(q--){
            int type;
            cin>>type;
            if(type){
                int p, q;
                cin>>p>>q;
                cout<<query(tree, 1, 0, n-1, p-1, q-1)<<endl;
            } else {
                int p, q, v;
                cin>>p>>q>>v;
                add_tree(tree, 1, 0, n-1, p-1, q-1, v);
            }
        }
        delete [] arr;
        delete [] tree;
    }
    return 0;
}