#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    ll data;
    Node * next;

    Node(ll d) : data(d), next(NULL){} 
};

void printLinkedList(Node * head){
    while(head != NULL){
        cout<<head->data<<endl;
        head = head->next;
    }
}

int main(){
    ll n;
    cin>>n;

    Node * head = NULL, * tail = NULL;

    for (ll i = 0; i < n; i++)
    {
        ll data;
        cin>>data;
        Node * temp = new Node(data);

        if(i == 0){
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = tail->next;
        }
    }
    
    printLinkedList(head);

    
    return 0;
}