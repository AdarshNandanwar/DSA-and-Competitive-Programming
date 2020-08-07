// https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return head;
        ListNode * cur = head, * prev = NULL, * temp;
        for(int i = 0; i<2 and cur; i++){
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        head->next = swapPairs(cur);
        return prev;
    }
};