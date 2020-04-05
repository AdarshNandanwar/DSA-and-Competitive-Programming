#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head) {
        ListNode * slow =head, *fast = head, * prev = head, *temp = head, *tail = head;
        
        if(head == NULL){
            return true;
        }
        
        while(tail->next != NULL){
            tail = tail->next;
        }
        
        while(fast != NULL){
            prev = slow;
            slow = slow->next;
            if(fast->next == NULL){
                break;
            } else {
                fast = fast->next->next;
            }
        }
        prev->next = tail;
        prev = NULL;
        while(slow!= NULL){
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;   
        }
        
        slow = head;
        while(slow!=NULL && tail !=NULL){
            if(slow->val == tail->val){
                slow = slow->next;
                tail = tail->next;
            } else {
                return false;
            }
        }
        return true;
    }