// Vasya vs Rhezo
// Send Feedback
// Queen Vasya is preparing for a war against Rhezo. She has N warriors in total arranged in a line. Let us number the warriors by numbers from 1 to N. She will fight Rhezo's army for Q days, and each day she can choose only one warrior.
// For each warrior, we know 2 values associated with him, let us call these A and B. Each day Vasya can choose her warrior from a range Li to Ri, she must choose the warrior with maximum A value. If there is more than 1 warrior having the same maximum A value, she chooses the warrior with minimum B value. If still there is more than 1 warrior with same maximum A value and same minimum B value, she chooses the one with lower index in line.
// You being the hand of Queen Vasya, need to help her in choosing the warrior for each day.
// Input:
// First line contains a single integer N, denoting the number of warriors Queen Vasya has. 
// Second line contains N space separated integers Ai. Third line contains N space separated integers Bi.
// Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
// Each of the next Q lines contains 2 integers Li and Ri.
// Output:
// For each Li and Ri, print the index of the warrior that Queen Vasya should choose.
// Constraints:
// 1≤ N,Q ≤10^6
// 1≤ Ai,Bi ≤10^9
// 1≤Li≤Ri
// Sample Input
// 5
// 1 8 4 6 8
// 4 8 6 3 7
// 4
// 1 4
// 2 4
// 3 4
// 1 5
// Sample Output
// 2
// 2
// 4
// 5

#include<bits/stdc++.h>
using namespace std;

struct warrior {
    int a;
    int b;
    int index;
};

void build_tree(int * arrA, int * arrB, warrior * tree, int tree_node, int start, int end){
    if(start == end){
        tree[tree_node] = { arrA[start], arrB[start], start};
        return;
    }
    int mid = (start+end)/2;
    build_tree(arrA, arrB, tree, 2*tree_node, start, mid);
    build_tree(arrA, arrB, tree, 2*tree_node+1, mid+1, end);
    warrior w1 = tree[2*tree_node];
    warrior w2 = tree[2*tree_node+1];
    if(w1.a > w2.a){
        tree[tree_node] = w1;
    } else if(w1.a == w2.a){
        if(w1.b > w2.b){
            tree[tree_node] = w2;
        } else if(w1.b == w2.b){
            if(w1.index > w2.index){
                tree[tree_node] = w2;
            } else {
                tree[tree_node] = w1;
            }
        } else {
            tree[tree_node] = w1;
        }
    } else {
        tree[tree_node] = w2;
    }
    return;
}

warrior find_tree(warrior * tree, int tree_node, int start, int end, int left, int right){
    if(left > end || right < start){
        return {INT_MIN, INT_MAX, INT_MAX};
    }
    if(left <= start && end <= right){
        return tree[tree_node];
    }
    int mid = (start+end)/2;
    warrior w1 = find_tree(tree, 2*tree_node, start, mid, left, right);
    warrior w2 = find_tree(tree, 2*tree_node+1, mid+1, end, left, right);
    warrior ans;
    if(w1.a > w2.a){
        ans = w1;
    } else if(w1.a == w2.a){
        if(w1.b > w2.b){
            ans = w2;
        } else if(w1.b == w2.b){
            if(w1.index > w2.index){
                ans = w2;
            } else {
                ans = w1;
            }
        } else {
            ans = w1;
        }
    } else {
        ans = w2;
    }
    return ans;
}

int main() {

	// Write your code here
    int n;
    cin>>n;
    int * arrA = new int[n];
    int * arrB = new int[n];
    warrior * tree = new warrior[4*n];
    for (int i = 0; i < n; i++)
    {
        cin>>arrA[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>arrB[i];
    }
    build_tree(arrA, arrB, tree, 1, 0, n-1);
    int q, x, y;
    cin>>q;
    while(q--){
        cin>>x>>y;
        warrior ans = find_tree(tree, 1, 0, n-1, x-1, y-1);
        cout<<ans.index+1<<endl;
    }
    delete [] arrA;
    delete [] arrB;
    delete [] tree;
    return 0;
}