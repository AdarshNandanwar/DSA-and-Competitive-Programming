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

// Method 2 (Slow Fast Pointer):

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto last = headA;
        while(last->next){
            last = last->next;
        }
        last->next = headA;
        auto slow = headB, fast = headB;
        if(fast->next == NULL){
            last->next = NULL;
            return NULL;
        }
        do{
            slow = slow->next;
            fast = fast->next->next;
        } while(fast and fast->next and slow != fast);
        if(slow != fast){
            last->next = NULL;
            return NULL;
        }
        slow = headB;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        last->next = NULL;
        return slow;
    }
};

// Method 3 (Finding Length, O(n) time, O(1) space):

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