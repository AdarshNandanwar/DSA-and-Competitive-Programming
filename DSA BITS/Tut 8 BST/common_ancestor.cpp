#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    int data;
    Node * left, * right;
    Node(int data):data(data), left(NULL), right(NULL){};
};

void insert(Node * & root, int data){
    if(root == NULL){
        root = new Node(data);
        return;
    }
    if(data < root->data){
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
    return;
}

void inorder(Node * root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node * root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node * root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int commonAncestor(Node * root, int d1, int d2){
    if(root == NULL){
        return -1;
    }
    if(d1 < root->data && d2 <root->data){
        return commonAncestor(root->left, d1, d2);
    } else if(d1 > root->data && d2 > root->data) {
        return commonAncestor(root->right, d1, d2);
    } else {
        return root->data;
    }
}

Node * root = NULL;
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, data;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>data;
        insert(root, data);
    }
    
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;

    cout<<"Common ansistors"<<endl;
    int d1, d2, t =5;
    while(t--){cin>>d1>>d2;
    cout<<commonAncestor(root, d1, d2)<<endl;}

    return 0;
}