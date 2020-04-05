#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{
    ll data;
    Node * left, * right;
    Node(ll data): data(data), left(NULL), right(NULL){};
};

Node * insert(Node * root, ll data){
    if(!root){
        return new Node(data);
    }
    if(data < root->data){
        root->left = insert(root->left, data);
    } else if(root->data < data){
        root->right = insert(root->right, data);
    }
    return root;
}

ll inOrderSuccessor(Node * root){
    if(!root || !root->right)
        return -1;
    Node * curr = root->right;
    while(curr->left)
        curr = curr->left;
    return curr->data;
}

ll inOrderPredecessor(Node * root){
    if(!root || !root->left)
        return -1;
    Node * curr = root->left;
    while(curr->right)
        curr = curr->right;
    return curr->data;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node * root = NULL;

    ll t;
    cin>>t;
    while(t--){
        ll data;
        cin>>data;
        root = insert(root, data);
    }
    cout<<inOrderPredecessor(root)<<endl;
    cout<<inOrderSuccessor(root)<<endl;
    return 0;
}