#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
	ll data;
	Node * next;

	Node(ll d): data(d), next(NULL){};
};

Node * head = NULL, * tail = NULL;

void printCircularList(){
	Node * curr = head;
	do{
		cout<<curr->data<<" ";
		curr = curr->next;
	}while(curr!= head);
	cout<<endl;
	return;
}

void deleteEven(){
	Node * curr = head;

	while(curr != NULL && curr->data % 2 == 0){
		if(curr->data%2 == 0){
			if(head == tail){
				head = tail = curr = NULL;
				return;
			} else {
				head = curr = curr->next;
				tail->next = head;
			}
		}
	}

	while(curr->next != head){
		if(curr->next->data %2 == 0){
			if(curr->next == tail){
				tail = curr;
			}
			curr->next = curr->next->next;
		} else {
			curr = curr->next;
		}
	}
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
			head = temp;
			temp->next = head;
			tail = temp;
		} else {
			tail->next = temp;
			temp->next = head;
			tail = temp;
		}
	}
	
	deleteEven();

	printCircularList();

	return 0;
}