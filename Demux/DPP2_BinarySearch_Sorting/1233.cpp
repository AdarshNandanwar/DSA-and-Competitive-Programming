// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/

// Method 1 (Sorting):

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        int n = folder.size(), prev = 0, j;
        if(n == 0) return ans;
        sort(folder.begin(), folder.end());
        ans.push_back(folder[0]);
        for(int i = 1; i<n; i++){
            if(folder[prev].length() > folder[i].length()){
                ans.push_back(folder[i]);
                prev = i;
            } else {
                for(j = 0; j<folder[prev].length(); j++){
                    if(folder[prev][j] != folder[i][j]){
                        ans.push_back(folder[i]);
                        prev = i;   
                        break;
                    }
                }
                if(j==folder[prev].length() and j<folder[i].length() and folder[i][j] != '/'){
                    ans.push_back(folder[i]);
                    prev = i;                    
                }
            }
        }
        return ans;
    }
};

// Method 2 (Tree):

struct Node{
    bool is_dir;
    unordered_map<string, Node *> m;
    
    Node(){
        is_dir = false;
        m.clear();
    }
};

void treeToVector(Node * root, string cur_path, vector<string> & ans){
    if(root->is_dir){
        ans.push_back(cur_path);
        return;
    }
    for(auto i:root->m){
        treeToVector(i.second, cur_path+"/"+i.first, ans);
    }
}

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Node * root = new Node();
        Node * curr;
        vector<string> ans;
        string sf;
        for(auto f:folder){
            curr = root;
            istringstream iss(f);
            getline(iss, sf, '/');
            while(getline(iss, sf, '/')){
                if(curr->is_dir){
                    break;
                }
                if(curr->m.find(sf) == curr->m.end()){
                    curr->m[sf] = new Node();
                }
                curr = curr->m[sf];
            }
            curr->is_dir = true;
            curr->m.clear();
        }
        treeToVector(root, "", ans);
        return ans;
    }
};