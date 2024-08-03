// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {INT_MAX, -1};

        int index = 1;
        int firstCriticalIndex = -1;
        int lastCriticalIndex = -1;
        int prev = head->val;
        ListNode * cur = head->next;
        while(cur->next){
            int next = cur->next->val;

            bool isLocalMinima = (prev > cur->val and cur->val < next);
            bool isLocalMaxima = (prev < cur->val and cur->val > next);
            bool isCriticalPoint = isLocalMinima or isLocalMaxima;

            if(isCriticalPoint){
                if(lastCriticalIndex != -1){
                    ans[0] = min(ans[0], index - lastCriticalIndex);
                    ans[1] = index - firstCriticalIndex;
                }

                lastCriticalIndex = index;
                if(firstCriticalIndex == -1){
                    firstCriticalIndex = index;
                }
            }

            prev = cur->val;
            cur = cur->next;
            index++;
        }

        return ans[0] == INT_MAX ? vector<int>(2, -1) : ans;
    }
};

// Method 2 (Recussion, O(n)):

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
    // {Distance to nearest critical point, Distance to last critical point}
    vector<int> helper(ListNode * head, int prev, vector<int> & ans){
        if(head == nullptr or head->next == nullptr){
            return {-1, -1};
        }
        
        auto distances = helper(head->next, head->val, ans);

        bool isLocalMinima = (prev > head->val and head->val < head->next->val);
        bool isLocalMaxima = (prev < head->val and head->val > head->next->val);
        bool isCriticalPoint = isLocalMinima or isLocalMaxima;

        if(isCriticalPoint and distances[0] != -1){
            ans[0] = min(ans[0], distances[0]);
            ans[1] = distances[1];
        }

        if(isCriticalPoint){
            if(distances[1] == -1){
                return {1, 1};
            } else {
                return {1, distances[1] + 1};
            }
        } else {
            if(distances[0] == -1){
                return {-1, -1};
            } else {
                return {distances[0] + 1, distances[1] + 1};
            }
        }
    }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {INT_MAX, INT_MIN};
        helper(head->next, head->val, ans);
        return ans[0] == INT_MAX ? vector<int>(2, -1) : ans;
    }
};
