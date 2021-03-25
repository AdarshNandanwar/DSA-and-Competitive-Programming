#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
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
    } else if(data > root->data){
        root->right = insert(root->right, data);
    }
    return root;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node * root = NULL;

    ll t, q;
    cin>>t>>q;
    while(t--){
        ll data;
        cin>>data;
        root = insert(root, data);
    }
    while(q--){
        ll k;
        cin>>k;
        cout<<solve(root, )
    }
    
    return 0;
}