// https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/

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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * end = head;
        for(int  i =0; i<k; i++){
            if(end == NULL) return head;
            end = end->next;
        }
        ListNode* curr = head, *prev = head, * temp;
        for(int i = 0; i<k; i++){
            if(curr == NULL) break;
            temp = curr->next;
            if(i != 0)
                curr->next = prev;
            else
                curr->next = reverseKGroup(end, k);
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};