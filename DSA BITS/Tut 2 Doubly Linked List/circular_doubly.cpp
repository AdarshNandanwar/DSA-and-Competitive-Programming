#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node * next, * prev;
    Node(int d): data(d), next(NULL), prev(NULL){};
};

Node * head = NULL;

void insert(int data){
    if(head == NULL){
        head = new Node(data);
        head->next = head;
        head->prev = head;
    } else {
        Node * tail = head->prev;
        Node * temp = new Node(data);
        head->next = temp;
        head->prev = temp;

    }
}

int main(){

    int n;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        int data;
        cin>>data;
        insert(data);
    }
    

    return 0;
}