// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

// Method 1 (input string stream, O(n)):

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    void constructString(TreeNode * root, string & s){
        if(root == NULL){
            s += "n,";
            return;
        }
        s += (to_string(root->val)+",");
        constructString(root->left, s);
        constructString(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        constructString(root, s);
        return s;
    }
    
    TreeNode * constructTree(istringstream & iss){
        string s;
        if(!getline(iss, s, ',')) return NULL;
        if(s == "n") return NULL;
        TreeNode * root = new TreeNode(stoi(s));
        root->left =  constructTree(iss);
        root->right =  constructTree(iss);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return constructTree(iss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));