#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{
	ll data;
	Node * next;
	Node * prev;

	Node(ll d): data(d), next(NULL), prev(NULL){}; 
};

Node * head = NULL, * tail = NULL;

void deleteLesser(ll k){
	Node * curr = head;
	while(curr != NULL){
		if(curr->data < k){
			if(curr->prev == NULL){
				head = curr->next;
				head->prev = NULL;
			} else {
				curr->prev->next = curr->next;
				if(curr->next != NULL){
					curr->next->prev = curr->prev;
				}
			}
		}
		curr = curr->next;
	}
	return;
}

void printList(){
	Node * curr = head;
	while(curr!= NULL){
		cout<<curr->data<<" ";
		curr = curr->next;
	}
	cout<<endl;
	return;
}

int main(){

	ll n, k;
	cin>>n;


	while(n--){
		ll data;
		cin>>data;

		Node * temp = new Node(data);

		if(head == NULL){
			head = tail = temp;
		} else {
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}

	}

	cin>>k;

	deleteLesser(k);

	printList();

	return 0;
}