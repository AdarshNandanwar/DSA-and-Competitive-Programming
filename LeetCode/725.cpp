// https://leetcode.com/problems/split-linked-list-in-parts/

// Method 1 (Dummy Node, O(n)):

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode * cur = head;
        while(cur){
            n++;
            cur = cur->next;
        }
        
        int q = n/k, r = n%k;
        ListNode dummy = ListNode();
        dummy.next = head;
        cur = &dummy;
        vector<ListNode *> v;
        for(int i = 0; i<k; i++){
            v.push_back(cur->next);
            for(int j = 0; j<q; j++) cur = cur->next;
            if(r-- > 0) cur = cur->next;
            dummy.next = cur->next;
            cur->next = NULL;
            cur = &dummy;
        }
        return v;
    }
};

// Altrnate Code (Dynamic memory allocation, O(n)):

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        
        ListNode * cur = head;
        while(cur){
            n++;
            cur = cur->next;
        }

        int minGroupSize = n / k;
        int extra = n % k;
        
        vector<ListNode *> parts;
        ListNode dummy;
        dummy.next = head;
        cur = &dummy;
        for(int i=0; i<k; i++){
            int listSize = minGroupSize;
            if(i<extra){
                listSize++;
            }
            cout<<listSize<<endl;

            parts.push_back(cur->next);
            while(listSize--){
                cur = cur->next;
            }

            ListNode * temp = cur->next;
            cur->next = nullptr;
            ListNode * curDummy = new ListNode();
            curDummy->next = temp;
            cur = curDummy;
        }

        return parts;
    }
};
