// https://leetcode.com/problems/find-duplicate-file-in-system/

// Method 1 (Hash Map, Input String Stream, O(n)):

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        
        for(auto & path:paths){
            istringstream iss(path);
            string dir, token;
            getline(iss, dir, ' ');
            while(getline(iss, token, ' ')){
                int i;
                for(i = 0; i<token.length() and token[i] != '('; i++);
                string file = token.substr(0, i), content = token.substr(i+1, token.length()-i-2);
                m[content].push_back(dir+'/'+file);
            }
        }
        for(auto & i:m){
            if(i.second.size() <= 1) continue;
            vector<string> v;
            for(auto & s:i.second){
                v.push_back(s);
            }
            res.push_back(v);
        }
        
        return res;
    }
};

// Method 1 (Hash Map, Input String Stream, O(n)):

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        int n = paths.size();
        unordered_map<string, vector<string>> contentToPath;
        for(int i=0; i<n; i++){
            istringstream issInfo(paths[i]);
            string path;
            getline(issInfo, path, ' ');
            string fileInfo;
            while(getline(issInfo, fileInfo, ' ')){
                string fileName, fileContent;
                istringstream issFile(fileInfo);
                getline(issFile, fileName, '(');
                getline(issFile, fileContent, '(');
                fileContent.pop_back();
                contentToPath[fileContent].push_back(path+"/"+fileName);
            }
        }
        vector<vector<string>> res;
        for(auto &i:contentToPath){
            if(i.second.size() > 1){
                res.push_back(i.second);
            }
        }
        return res;
    }
};