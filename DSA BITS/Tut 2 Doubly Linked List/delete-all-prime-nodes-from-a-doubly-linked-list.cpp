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

bool isPrime(ll n){
	if(n<=1){
		return false;
	}
	if(n<=3){
		return true;
	}
	for (int i = 2; i*i <= n; ++i)
	{
		if(n%i == 0){
			return false;
		}
	}
	return true;
}

void deletePrime(){
	Node * curr = head;
	while(curr != NULL){
		if(isPrime(curr->data)){
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

	ll n;
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

	deletePrime();

	printList();

	return 0;
}