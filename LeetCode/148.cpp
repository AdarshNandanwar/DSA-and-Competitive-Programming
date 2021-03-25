// https://leetcode.com/problems/sort-list/

// Method 1 (dummy method, O(nlogn) time, O(1) space):

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
    
    ListNode* merge(ListNode* A, int na, ListNode* B, int nb){
        
        ListNode da, db;
        da.next = A;
        db.next = B;
        ListNode * ca = &da, * cb = &db, * temp = NULL;
        
        while(na and nb){
            if(ca->next->val <= cb->next->val){
                ca = ca->next;
                na--;
            } else {
                temp = ca->next;
                ca->next = cb->next;
                cb->next = cb->next->next;
                ca = ca->next;
                ca->next = temp;
                nb--;
            }
        }
        while(na){
            ca = ca->next;
            na--;
        }
        while(nb){
            temp = ca->next;
            ca->next = cb->next;
            cb->next = cb->next->next;
            ca = ca->next;
            ca->next = temp;
            nb--;
        }
        
        // VERY IMP : CONNECT THE LAST NODE IN SORTED LIST TO THE NEXT NODE OF THE LAST NODE OF B
        ca->next = cb->next;
        
        return da.next;
    }

    ListNode* mergeSort(ListNode* A, int n){
        if(n <= 1) return A;
        int mid = n/2;
        ListNode * B = A;
        for(int i = 0; i<mid; i++) B = B->next;
        A = mergeSort(A, mid);
        B = mergeSort(B, n-mid);
        return merge(A, mid, B, n-mid);
    }    
    
    ListNode* sortList(ListNode* head) {
        int n = 0;
        ListNode * cur = head;
        while(cur){
            n++;
            cur = cur->next;
        }
        return mergeSort(head, n);
    }
};

// Method 2 (prev ptr method, O(nlogn) time, O(1) space):

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
    
    ListNode* merge(ListNode* A, int na, ListNode* B, int nb){
        ListNode * head = NULL, * prev = NULL, * curA = A, * curB = B;
        int i = 0, j = 0;
        while(i<na and j<nb){
            if(curA->val > curB->val){
                if(prev){
                    prev->next = curB;
                    prev = prev->next;
                } else {
                    head = prev = curB;
                }
                curB = curB->next;
                j++;
            } else {
                if(prev){
                    prev->next = curA;
                    prev = prev->next;
                } else {
                    head = prev = curA;
                }
                curA = curA->next;
                i++;
            }
        }
        while(i<na){
            if(prev){
                prev->next = curA;
                prev = prev->next;
            } else {
                head = prev = curA;
            }
            curA = curA->next;
            i++;
        }
        while(j<nb){
            if(prev){
                prev->next = curB;
                prev = prev->next;
            } else {
                head = prev = curB;
            }
            curB = curB->next;
            j++;
        }
        prev->next = curB;
        return head;
    }

    ListNode* mergeSort(ListNode* A, int n){
        if(n <= 1) return A;
        int mid = n/2;
        ListNode * B = A;
        for(int i = 0; i<mid; i++) B = B->next;
        A = mergeSort(A, mid);
        B = mergeSort(B, n-mid);
        return merge(A, mid, B, n-mid);
    }    
    
    ListNode* sortList(ListNode* head) {
        int n = 0;
        ListNode * cur = head;
        while(cur){
            n++;
            cur = cur->next;
        }
        return mergeSort(head, n);
    }
};