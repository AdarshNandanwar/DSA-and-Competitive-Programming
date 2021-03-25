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
        root->left = insert(root->left, data);
    } else if (root->data < data){
        root->right = insert(root->right, data);
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
    return;
}

ll printSize(Node * root){
    if(root == NULL){
        return 0;
    }
    ll size = printSize(root->left)+printSize(root->right) + 1;
    cout<<root->data<<": "<<size<<endl;
    return size;
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
    printSize(root);
    return 0;
}