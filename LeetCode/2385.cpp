// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/

// Method 1 (Only recursion, O(n) time, O(1) space):

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    // {nodes in longest path from root to leaf, nodes in path from root to start}
    pair<int, int> GetDistance(const TreeNode * root, const int& val, int& maxDistance){
        if(root == nullptr){
            return make_pair(0, -1);
        }

        pair<int, int> left = GetDistance(root->left, val, maxDistance);
        pair<int, int> right = GetDistance(root->right, val, maxDistance);
        
        int nodesInLongestPathToLeaf = 1 + max(left.first, right.first);
        if(root->val == val){
            maxDistance = max(maxDistance, max(left.first, right.first));
            return make_pair(nodesInLongestPathToLeaf, 1);
        } else {
            if(left.second == -1 and right.second == -1){
                // start is not in this subtree
                return make_pair(nodesInLongestPathToLeaf, -1);
            } else if(left.second == -1 and right.second != -1){
                // right has start
                maxDistance = max(maxDistance, left.first + right.second);
                return make_pair(nodesInLongestPathToLeaf, 1 + right.second);
            } else if(left.second != -1 and right.second == -1){
                // left has start
                maxDistance = max(maxDistance, left.second + right.first);
                return make_pair(nodesInLongestPathToLeaf, 1 + left.second);
            } else if(left.second != -1 and right.second != -1){
                // both have start
                // not possible
            }
        }
        return make_pair(-1, -1);
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        int nodesInLongestPathFromStartToLeaf = -1;
        GetDistance(root, start, nodesInLongestPathFromStartToLeaf);
        return nodesInLongestPathFromStartToLeaf;
    }
};

// Method 2 (Parent Hash Map, BFS, O(n) time, O(n) space):

class Solution {
    void AssignParents(TreeNode * root, TreeNode * parent, unordered_map<TreeNode *, TreeNode *>& parents){
        if(root == nullptr){
            return;
        }
        parents[root] = parent;
        AssignParents(root->left, root, parents);
        AssignParents(root->right, root, parents);
    }

    TreeNode * Find(TreeNode * root, int val){
        if(root == nullptr){
            return nullptr;
        }
        if(root->val == val){
            return root;
        }
        TreeNode * left = Find(root->left, val);
        if(left){
            return left;
        }
        TreeNode * right = Find(root->right, val);
        if(right){
            return right;
        }
        return nullptr;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode *, TreeNode *> parents;
        AssignParents(root, nullptr, parents);
        TreeNode * startNode = Find(root, start);

        unordered_set<TreeNode *> visited;
        int time = -1;
        queue<TreeNode *> q;
        q.push(startNode);
        visited.insert(startNode);
        while(!q.empty()){
            int sz = q.size();
            time++;
            while(sz--){
                TreeNode * cur = q.front();
                q.pop();
                if(cur->left and visited.count(cur->left) == 0){
                    q.push(cur->left);
                    visited.insert(cur->left);
                }
                if(cur->right and visited.count(cur->right) == 0){
                    q.push(cur->right);
                    visited.insert(cur->right);
                }
                if(parents[cur] and visited.count(parents[cur]) == 0){
                    q.push(parents[cur]);
                    visited.insert(parents[cur]);
                }
            }
        }
        return time;
    }
};

// Alternate Code (Full Graph Construction, BFS, O(n) time, O(n) space):

class Solution {
    void ConstructGraph(TreeNode * root, unordered_map<int, vector<int>>& adj){
        if(root == nullptr){
            return;
        }
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        ConstructGraph(root->left, adj);
        ConstructGraph(root->right, adj);
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        ConstructGraph(root, adj);

        unordered_set<int> visited;
        int time = -1;
        queue<int> q;
        q.push(start);
        visited.insert(start);
        while(!q.empty()){
            int sz = q.size();
            time++;
            while(sz--){
                int cur = q.front();
                q.pop();
                for(int nbr:adj[cur]){
                    if(visited.count(nbr) == 0){
                        q.push(nbr);
                        visited.insert(nbr);
                    }
                }
            }
        }
        return time;
    }
};