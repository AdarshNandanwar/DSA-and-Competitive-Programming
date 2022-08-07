// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

// Method 1 (O(n)):

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode dummy;
        dummy.next = head;
        ListNode * cur = &dummy;
        int n = 0;
        while(cur->next){
            n++;
            cur = cur->next;
        }
        ListNode * p1 = &dummy, * p2 = &dummy;
        if(k-1>n-k) k = n-k+1;
        for(int i=0; i<k-1; i++){
            p1 = p1->next;
        }
        for(int i=0; i<n-k; i++){
            p2 = p2->next;
        }
        if(p1 == p2) return dummy.next;
        if(p1->next == p2 or p2->next == p1){
            p1->next = p2->next;
            p2->next = p2->next->next;
            p1->next->next = p2;
        } else {
            swap(p1->next->next, p2->next->next);
            swap(p1->next, p2->next);   
        }
        
        return dummy.next;
    }
};