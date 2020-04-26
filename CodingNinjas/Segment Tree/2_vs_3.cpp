// 2 vs 3
// Send Feedback
// The fight for the best number in the globe is going to finally come to an end.The top two contenders for the best number are number 2 and number 3.It's the final the entire world was waiting for. Expectorates from all across the globe came to witness the breath taking finals.
// The finals began in an astonishing way.A common problem was set for both of them which included both these number.The problem goes like this.
// Given a binary string (that is a string consisting of only 0 and 1). They were supposed to perform two types of query on the string.
// Type 0: Given two indices l and r.Print the value of the binary string from l to r modulo 3.

// Type 1: Given an index l flip the value of that index if and only if the value at that index is 0.
// The problem proved to be a really tough one for both of them.Hours passed by but neither of them could solve the problem.So both of them wants you to solve this problem and then you get the right to choose the best number in the globe.
// Input:
// The first line contains N denoting the length of the binary string .
// The second line contains the N length binary string.Third line contains the integer Q indicating the number of queries to perform.
// This is followed up by Q lines where each line contains a query.
// Output:
// For each query of Type 0 print the value modulo 3.
// Constraints:
// 1<= N <=10^5

// 1<= Q <= 10^5

// 0 <= l <= r < N
// Sample Input
// 5
// 10010
// 6
// 0 2 4
// 0 2 3
// 1 1
// 0 0 4
// 1 1
// 0 0 3
// Sample Output
// 2
// 1
// 2
// 1

#include<bits/stdc++.h>
using namespace std;

void create_tree(int * arr, int * power, int * tree, int tree_node, int start, int end){
    if(start == end){
        tree[tree_node] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    create_tree(arr, power, tree, 2*tree_node, start, mid);
    create_tree(arr, power, tree, 2*tree_node+1, mid+1, end);
    tree[tree_node] = ((tree[2*tree_node]*power[end-mid])%3 + tree[2*tree_node+1])%3;
    return;
}

int query(int * tree, int * power, int tree_node, int start, int end, int left, int right){
    if(left > end || right < start){
        return 0;
    }
    if(start >= left && right >= end){
        return (tree[tree_node]*power[right-end])%3;
    }    
    int mid = (start+end)/2;
    int option1 = query(tree, power, 2*tree_node, start, mid, left, right);
    int option2 = query(tree, power, 2*tree_node+1, mid+1, end, left, right);
    return (option1 + option2)%3;
}

void update_tree(int * tree, int * power, int tree_node, int start, int end, int index){
    if(start == end){
        tree[tree_node] = 1;
        return;
    }
    int mid = (start+end)/2;
    if(mid >= index){
        update_tree(tree, power, 2*tree_node, start, mid, index);
    } else {
        update_tree(tree, power, 2*tree_node+1, mid+1, end, index);
    }
    tree[tree_node] = ((tree[2*tree_node]*power[end-mid])%3 + tree[2*tree_node+1])%3;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, q, x, y;
    string str;
    cin>>n;
    cin>>str;
    int * arr = new int[n];
    int * tree = new int[4*n]();
    int * power = new int[n]();
    for (int i = 0; i < n; i++)
    {
        arr[i] = str[i] - 48;
    }
    power[0] = 1;
    for (int i = 1; i < n; i++)
    {
        power[i] = (power[i-1]*2)%3;
    }
    create_tree(arr, power, tree, 1, 0, n-1);
    
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type == 0){
            cin>>x>>y;
            cout<<query(tree, power, 1, 0, n-1, x, y)<<endl;
        } else {
            cin>>x;
            update_tree(tree, power, 1, 0, n-1, x);
        }
    }
    delete [] tree;
    delete [] power;
    return 0;
}