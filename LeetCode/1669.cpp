// https://leetcode.com/problems/merge-in-between-linked-lists/

// Method 1 (Loop, O(n)):

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode * cur = list1;
        for(int i=0; i<a-1; i++){
            cur = cur->next;
        }
        ListNode * secondHead = cur;
        for(int i=0; i<b-a+2; i++){
            secondHead = secondHead->next;
        }
        cur->next = list2;
        while(cur->next){
            cur = cur->next;
        }
        cur->next = secondHead;
        return list1;
    }
};