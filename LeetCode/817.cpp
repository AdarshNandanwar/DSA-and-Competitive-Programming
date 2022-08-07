// https://leetcode.com/problems/linked-list-components/

// Method 1 (Union Find with rank and path compression, O()):

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
    int getRoot(int x, vector<int> & id){
        if(id[x] == x){
            return x;
        }
        return id[x] = getRoot(id[x], id);
    }
    
    void merge(int root1, int root2, vector<int> & sz, vector<int> & id){
        if(sz[root1] < sz[root2]){
            swap(root1, root2);
        }
        sz[root1] += sz[root2];
        id[root2] = id[root1];
    }
    
    int numComponents(ListNode* head, vector<int>& nums) {
        int n = 0;
        for(auto cur = head; cur; cur = cur->next){
            n++;
        }
        vector<int> sz(n, 1), id(n);
        for(int i=0; i<n; i++){
            id[i] = i;
        }
        
        int componentCount = nums.size();
        unordered_set<int> nodes(nums.begin(), nums.end());
        
        for(auto cur = head; cur and cur->next; cur = cur->next){
            int node1 = cur->val;
            int node2 = cur->next->val;
            if(!nodes.count(node1) or !nodes.count(node2)){
                continue;
            }
            int root1 = getRoot(node1, id);
            int root2 = getRoot(node2, id);
            if(root1 == root2){
                continue;
            }
            merge(root1, root2, sz, id);
            componentCount--;
        }
        return componentCount;
    }
};