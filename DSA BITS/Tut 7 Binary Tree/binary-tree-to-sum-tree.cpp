#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    ll data;
    Node * left, * right;
    Node(ll data): data(data), left(NULL), right(NULL){};
};

Node * insert(Node * root, ll data){
    if(root == NULL){
        return new Node(data);
    }
    if(data < root->data){
        root->left = insert(root->left, data);
    } else if(root->data < data){
        root->right = insert(root->right, data);
    }
    return root;
}

ll convertToSumTree(Node * & root){
    if(root == NULL){
        return 0;
    }
    root->data += convertToSumTree(root->right);
    root->data += convertToSumTree(root->left);
    return root->data;
}

void inOrder(Node * root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
    return;
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node * root = NULL;

    ll n;
    cin>>n;
    while(n--){
        ll data;
        cin>>data;
        root = insert(root, data);
    }
    convertToSumTree(root);
    inOrder(root);

    return 0;
}