// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/

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
    int get_gcd(int a, int b){
        if(a % b == 0){
            return b;
        }
        return gcd(b, a%b);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode * cur = head;
        while(cur->next){
            int gcd = get_gcd(cur->val, cur->next->val);
            ListNode * gcdNode = new ListNode(gcd, cur->next);
            cur->next = gcdNode;
            cur = gcdNode->next;
        }
        return head;
    }
};
