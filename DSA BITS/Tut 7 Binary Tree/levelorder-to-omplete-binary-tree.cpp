#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{
    ll data;
    Node * left, * right;
};

Node * constructTree(ll * arr, ll index, ll n){
    if(index < n){
        Node * root = new Node();
        root->data = arr[index];
        root->left = constructTree(arr, 2*index+1, n);
        root->right = constructTree(arr, 2*index+2, n);
        return root;
    } else {
        return NULL;
    }
}

void inOrder(Node * root){
    if(!root){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll arr[] = {1, 2, 3, 4, 5, 6, 6, 6, 6, 6}, n = 10;
    Node * root = NULL;

    root = constructTree(arr, 0, n);
    inOrder(root);

    return 0;
}