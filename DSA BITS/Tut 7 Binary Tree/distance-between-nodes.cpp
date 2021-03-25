#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
struct Node{
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
    } if (root->data < data){
        root->right = insert(root->right, data);
    }
    return root;
}

ll commonAncestorLevel(Node * root, ll d1, ll d2){
    if(root == NULL){
        return 0;
    }
    if(max(d1, d2) < root->data){
        return 1+commonAncestorLevel(root->left, d1, d2);
    } else if(root->data < min(d1, d2)){
        return 1+commonAncestorLevel(root->right, d1, d2);
    } else {
        return 0;
    }
}

ll nodeLevel(Node * root, ll data){
    if(root == NULL){
        return INT_MIN;
    }
    if(data < root->data){
        return 1+nodeLevel(root->left, data);
    } else if(root->data < data){
        return 1+nodeLevel(root->right, data);
    } else {
        return 0;
    }
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
    ll d1, d2;
    cin>>d1>>d2;
    cout<<nodeLevel(root, d1)+nodeLevel(root, d2)-commonAncestorLevel(root, d1, d2)*2<<endl;
    return 0;
}