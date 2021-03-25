// https://leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        int n = 0;
        ListNode* cur = head, * newHead;
        while(cur){
            cur = cur->next;
            n++;
        }
        k = k%n;
        if(k == 0) return head;
        int m = n-k-1;
        cur = head;
        while(m--) cur = cur->next;
        newHead = cur->next;
        cur->next = NULL;
        cur = newHead;
        while(cur->next) cur = cur->next;
        cur->next = head;
        return newHead;
    }
};