// https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum, carry = 0;
        ListNode dummy = ListNode();
        ListNode * cur = &dummy;
        while(l1 and l2){
            sum = l1->val+l2->val+carry;
            carry = sum/10;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            sum = l1->val+carry;
            carry = sum/10;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            l1 = l1->next;
        }
        while(l2){
            sum = l2->val+carry;
            carry = sum/10;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            l2 = l2->next;
        }
        while(carry){
            sum = carry;
            carry = sum/10;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
        }
        return dummy.next;
    }
};

// Alternate Code

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
    ListNode* addTwoNumbers(ListNode* A, ListNode* B) {
        int carry = 0, temp;
        ListNode * head = NULL, * cur = NULL;

        while(A and B){
            temp = A->val+B->val+carry;
            if(head){
                cur->next = new ListNode(temp%10);
                cur = cur->next;
            } else {
                head = cur = new ListNode(temp%10);
            }
            carry = temp/10;
            A = A->next;
            B = B->next;
        }
        while(A){
            temp = A->val+carry;
            if(head){
                cur->next = new ListNode(temp%10);
                cur = cur->next;
            } else {
                head = cur = new ListNode(temp%10);
            }
            carry = temp/10;
            A = A->next;
        }
        while(B){
            temp = B->val+carry;
            if(head){
                cur->next = new ListNode(temp%10);
                cur = cur->next;
            } else {
                head = cur = new ListNode(temp%10);
            }
            carry = temp/10;
            B = B->next;
        }
        if(carry){
            temp = carry;
            if(head){
                cur->next = new ListNode(temp%10);
                cur = cur->next;
            } else {
                head = cur = new ListNode(temp%10);
            }
            carry = temp/10;
        }
        return head;
    }
};