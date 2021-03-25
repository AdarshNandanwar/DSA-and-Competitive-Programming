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
    } else if(root->data <data){
        root->right = insert(root->right, data);
    } else {
        return root;
    }
}

ll findLevel(Node * root, ll data){
    if(root == NULL || root->data == data){
        return 0;
    }
    if(data < root->data){
        return 1 + findLevel(root->left, data);
    } else {
        return 1 + findLevel(root->right, data);
    }
}

void printLevel(Node * root, ll level){
    if(root == NULL){
        return;
    }
    if(level){
        printLevel(root->left, level-1);
        printLevel(root->right, level-1);
    } else {
        cout<<root->data<<" ";
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin>>n>>k;
    Node * root = NULL;
    while(n--){
        ll data;
        cin>>data;
        root = insert(root, data);
    }
    ll level = findLevel(root, k);
    printLevel(root, level);
    return 0;
}