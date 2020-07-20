// https://leetcode.com/problems/insertion-sort-list/

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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode * headSort = new ListNode(head->val);
        ListNode * curSort = headSort;
        ListNode * prevSort = NULL;
        ListNode * cur = head->next;
        
        while(cur){
            while(curSort and curSort->val <= cur->val){
                prevSort = curSort;
                curSort = curSort->next;
            }
            if(prevSort){
                prevSort->next = new ListNode(cur->val, prevSort->next);
            } else {
                headSort = new ListNode(cur->val, headSort);
            }
            cur = cur->next;
            curSort = headSort;
            prevSort = NULL;
        }
        return headSort;
    }
};