#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node * next, * prev;
    Node(int d): data(d), next(NULL), prev(NULL){};
};

void printList(Node * head){
    Node * curr = head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

void insertEnd(Node * & head, Node * & tail, int data){
    Node * curr = new Node(data);
    if(head == NULL){
        head = curr;
        tail = curr;
    } else {
        tail->next = curr;
        curr->prev = tail;
        tail = curr;
    }
}

void reverseList(Node * & head, Node * & tail){
    Node * curr = head, * temp;
    while(curr != NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    temp = tail;
    tail = head;
    head = temp;
}

int main(){

    int n;
    cin>>n;

    Node * head = NULL, * tail = NULL;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin>>data;
        insertEnd(head, tail, data);
    }
    // printList(head);

    reverseList(head, tail);

    printList(head);    

    return 0;
}