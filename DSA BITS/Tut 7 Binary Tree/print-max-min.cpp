#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
struct Node{
    ll data, max_data, min_data;
    Node * left, * right;
    Node(ll data): data(data), left(NULL), right(NULL), max_data(data), min_data(data){};
};

ll getMaxData(Node * root){
    if(root == NULL){
        return INT_MIN;
    }
    return root->max_data;
}

ll getMinData(Node * root){
    if(root == NULL){
        return INT_MAX;
    }
    return root->min_data;
}

Node * insert(Node * root, ll data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(data < root->data){
        root->left = insert(root->left, data);
    } else if(root->data < data){
        root->right = insert(root->right, data);
    }
    root->max_data = max(root->data, max(getMaxData(root->left), getMaxData(root->right)));
    root->min_data = min(root->data, min(getMinData(root->left), getMinData(root->right)));
    return root;
}

void inOrder(Node * root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<": "<<"max = "<<root->max_data<<", min = "<<root->min_data<<endl;
    inOrder(root->right);
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
    inOrder(root);

    return 0;
}