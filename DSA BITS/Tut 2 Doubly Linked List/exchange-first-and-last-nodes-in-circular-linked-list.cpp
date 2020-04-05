#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
	ll data;
	Node * next;

	Node(ll d): data(d), next(NULL){};
};


void printCircularList(Node * head){
	Node * curr = head;
	do{
		cout<<curr->data<<" ";
		curr = curr->next;
	}while(curr!= head);
	cout<<endl;
	return;
}

Node * exchangeFirstLastNodes(Node * head){
	// Use only one extra node

	Node * curr = head;

	while(curr->next->next != head){
		curr = curr->next;
	}

	Node * temp = curr->next;
	curr->next = curr->next->next;
	temp->next = curr->next->next;
	curr->next->next = temp;
	return temp;
}

int main(){
	ll n;
	cin>>n;
	Node * head = NULL, * tail = NULL;
	while(n--){
		ll data;
		cin>>data;
		Node * temp = new Node(data);
		if(head == NULL){
			head = temp;
			temp->next = head;
			tail = temp;
		} else {
			tail->next = temp;
			temp->next = head;
			tail = temp;
		}
	}
	
	head = exchangeFirstLastNodes(head);

	printCircularList(head);

	return 0;
}