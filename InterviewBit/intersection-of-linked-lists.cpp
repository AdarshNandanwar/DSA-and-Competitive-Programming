// https://www.interviewbit.com/problems/intersection-of-linked-lists/

// Method 1 (O(n) time, O(1) space):

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ListNode * curA = A, * curB = B;
    while(curA != curB){
        curA = curA ? curA->next : B;
        curB = curB ? curB->next : A;
    }
    return curA;
}

// Method 2 (calculating length, O(n) time, O(1) space):

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
int getLen(ListNode * A){
    int c = 0;
    while(A){
        c++;
        A = A->next;
    }
    return c;
}
 
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

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

// Method 3 (Hash table, O(n) time, O(n) space):

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    unordered_set<ListNode*> s;
    while(A){
        s.insert(A);
        A = A->next;
    }
    while(B){
        if(s.count(B)) return B;
        B = B->next;
    }
    return NULL;
}
