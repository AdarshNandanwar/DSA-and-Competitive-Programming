// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// Method 1 (2 Pointer, O(n)):

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
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * slow = head, * fast = head;
        for(int  i = 0; i<n+1; i++){
            if(fast == NULL){
                return head->next;
            }
            fast = fast->next;
        }
        while(fast!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

// Method 2 (Recursion, O(n)):

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
    int helper(ListNode* head, int n){
        if(head->next->next == NULL){
            if(n == 1) head->next = NULL;
            return 1;
        }
        int index = helper(head->next, n)+1;
        if(index == n) head->next = head->next->next;
        return index;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy;
        dummy.next = head;
        helper(&dummy, n);
        return dummy.next;
    }
};