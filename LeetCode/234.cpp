// https://leetcode.com/problems/palindrome-linked-list/

// Method 1 (Floyd Slow Fast Pointer):

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

// Method 2 (Linear):

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
    
    int get_size(ListNode* head){
        int n = 0;
        while(head){
            n++;
            head = head->next;
        }
        return n;
    }
    
    ListNode* get_reverse(ListNode* head){
        ListNode * prev = NULL, * temp = NULL;
        while(head){
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode dummy(0, head);
        
        int n = get_size(head);
        
        ListNode * mid = &dummy;
        for(int i = 0; i<(n+1)/2; i++){
            mid = mid->next;
        }
        
        ListNode * rev_head = get_reverse(mid->next);
        mid->next = NULL;
        
        while(rev_head and head){
            if(rev_head->val != head->val) return false;
            head = head->next;
            rev_head = rev_head->next;
        }
        return true;
    }
};