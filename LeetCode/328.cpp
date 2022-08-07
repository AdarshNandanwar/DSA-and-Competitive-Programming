// https://leetcode.com/problems/odd-even-linked-list/

// Method 1 (Linked List, O(n) time, O(1) space):

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ListNode * p1 = head;
        ListNode * p2 = head->next;
        while(p2 and p2->next){
            ListNode * temp = p1->next;
            p1->next = p2->next;
            p2->next = p1->next->next;
            p1->next->next = temp;
            p1 = p1->next;
            p2 = p2->next;
        }
        return head;
    }
};

// Alternate Code:

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode * p1 = head, * p2 = head->next;
        while(p2 and p2->next){
            auto temp = p1->next;
            p1 = p1->next = p2->next;
            p2 = p2->next = p2->next->next;
            p1->next = temp;
        }
        return head;
    }
};