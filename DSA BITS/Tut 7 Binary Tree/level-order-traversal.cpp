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
    } else if(root->data < data){
        root->right = insert(root->right, data);
    }
    return root;
}

void levelOrder(Node * root){
    if(root == NULL){
        return;
    }
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        cout<<q.front()->data<<" ";
        if(q.front()->left){
            q.push(q.front()->left);
        }
        if(q.front()->right){
            q.push(q.front()->right);
        }
        q.pop();
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
    levelOrder(root);

    return 0;
}