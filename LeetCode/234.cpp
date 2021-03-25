// https://leetcode.com/problems/palindrome-linked-list/

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
    ListNode * revList(ListNode * head){
        ListNode * cur = head, * prev = NULL, * temp = NULL;
        while(cur){
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head) return 1;
        ListNode * slow = head, * fast = head, * prev = NULL;
        do{
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        } while(fast);

        prev->next = revList(slow);

        ListNode * p1 = head, * p2 = prev->next;
        while(p1 and p2){
            if(p1->val != p2->val) return 0;
            p1 = p1->next;
            p2 = p2->next;
        }
        return 1;
    }
};