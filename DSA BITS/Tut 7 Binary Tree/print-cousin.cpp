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

void printCousin(Node * root, ll level, ll s1, ll s2){
    if(root == NULL){
        return;
    }
    if(level){
        printCousin(root->left, level-1, s1, s2);
        printCousin(root->right, level-1, s1, s2);
    } else if(root->data != s1 && root->data != s2){
        cout<<root->data<<" ";
    }
}

void printCousin(Node * root, ll level, ll s1){
    if(root == NULL){
        return;
    }
    if(level){
        printCousin(root->left, level-1, s1);
        printCousin(root->right, level-1, s1);
    } else if(root->data != s1){
        cout<<root->data<<" ";
    }
}

Node * findSibling(Node * root, ll data){
    if(root == NULL || root->data == data){
        return NULL;
    }
    if(data < root->data){
        if(root->left != NULL){
            if(root->left->data == data){
                return root->right;
            } else{
                return findSibling(root->left, data);
            }
        }
    } else {
        if(root->right != NULL){
            if(root->right->data == data){
                return root->left;
            } else {
                return findSibling(root->right, data);
            }
        }
    }
    return NULL;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin>>n;
    Node * root = NULL;
    while(n--){
        ll data;
        cin>>data;
        root = insert(root, data);
    }
    cin>>k;
    ll level = findLevel(root, k);
    Node * sibling = findSibling(root, k);
    if(sibling != NULL){
        printCousin(root, level, k, sibling->data);
    } else {
        printCousin(root, level, k);
    }
    return 0;
}