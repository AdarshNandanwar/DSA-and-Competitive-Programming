#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{
    ll data;
    Node * left, * right;
    Node(ll data):data(data), left(NULL), right(NULL){};
};

Node * insert(Node * root, ll data){
    if(root == NULL){
        return new Node(data);
    }
    if(data < root->data){
        root->left =  insert(root->left, data);
    } else if(root->data < data){
        root->right =  insert(root->right, data);
    }
    return root;
}

void inOrder(Node * root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

ll counter = 0;

void nthNodeInOrder(Node * root, ll k){
    if(root == NULL){
        return;
    }
    nthNodeInOrder(root->left, k);
    if(++counter == k) cout<<root->data<<endl;
    nthNodeInOrder(root->right, k);
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node * root = NULL;

    ll n, k;
    cin>>n>>k;
    while(n--){
        ll data;
        cin>>data;
        root = insert(root, data);
    }
    nthNodeInOrder(root, k);
    return 0;
}