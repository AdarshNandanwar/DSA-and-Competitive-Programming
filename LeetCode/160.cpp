// https://leetcode.com/problems/intersection-of-two-linked-lists/

// Method 1 (O(n) time, O(1) space):

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        ListNode * curA = A, * curB = B;
        while(curA != curB){
            curA = curA ? curA->next : B;
            curB = curB ? curB->next : A;
        }
        return curA;
    }
};

// Method 2 (Finding Length, O(n) time, O(1) space):

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLen(ListNode * A){
        int c = 0;
        while(A){
            c++;
            A = A->next;
        }
        return c;
    }
    
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        ListNode * curA = A, * curB = B;
        int la = getLen(A), lb = getLen(B);
        if(la < lb) swap(curA, curB);
        for(int i = 0; i<abs(la-lb); i++) curA = curA->next;
        while(curA and curB and curA != curB){
            curA = curA->next;
            curB = curB->next;
        }
        return curA;
    }
};