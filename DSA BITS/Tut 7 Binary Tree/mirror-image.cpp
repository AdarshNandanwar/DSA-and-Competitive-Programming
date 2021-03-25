#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{
    ll data;
    Node * right, * left;
    Node(ll data):data(data), left(NULL), right(NULL){};
};

void insert(Node * & root, ll pos, ll data, char branch){
    if(root == NULL){
        return;
    }
    if(root->data == pos){
        if(branch == 'L'){
            root->left = new Node(data);
        } else {
            root->right = new Node(data);
        }
    } else {
        insert(root->left, pos, data, branch);
        insert(root->right, pos, data, branch);
    }
    return;
}

ll mirrorImage(Node * root, Node * mirror, ll data){
    if(!root || !mirror){
        return -1;
    }
    if(root->data == data)
        return mirror->data;
    else
        return max(mirrorImage(root->left, mirror->right, data), mirrorImage(root->right, mirror->left, data));
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node * root = new Node(1);
    Node * mirror = new Node(1);

    ll N, Q;
    ll pos, data;
    char branch;
    cin>>N>>Q;
    N--;
    while(N--){
        cin>>pos>>data>>branch;
        insert(root, pos, data, branch);
        insert(mirror, pos, data, branch);
    }
    while(Q--){
        ll q;
        cin>>q;
        cout<<mirrorImage(root, mirror, q)<<endl;
    }
    return 0;
}