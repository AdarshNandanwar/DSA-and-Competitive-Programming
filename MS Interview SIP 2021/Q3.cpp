#include<bits/stdc++.h>
using namespace std;

ListNode * reverseList(ListNode * head){
    ListNode * prev = NULL, * cur = head, * temp = NULL;
    while(cur){
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}

ListNode * solve(ListNode * head){

    if(head == NULL) return NULL;

    ListNode * curOrignal = head, * slow = head, * fast = head, * curRev = NULL, * temp = NULL;

    while(fast->next and fast->next->next){
        slow = slow->next;
        fast = fast->next;
        if(fast->next){
            fast = fast->next;
        }
    }

    

    ListNode * head2 = slow->next;
    slow->next = NULL;

    head2 = reverseList(head2);

    // merge 2 list

    curOrignal = head;
    curRev = head2;

    while(curOrignal and curRev){
        temp = curOriginal->next;
        curOriginal->next = curRev;
        curRev = curRev->next;
        curOriginal = curOriginal->next;
        curOriginal->next = temp;
        curOriginal = curOriginal->next;
    }

    return head;
}