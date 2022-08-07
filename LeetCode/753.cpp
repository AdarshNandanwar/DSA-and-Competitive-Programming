// https://leetcode.com/problems/cracking-the-safe/

// Method 1 (DFS, O(k^n + (k^n)*k)):

class Solution {
public:
    bool dfs(string password, const int & targetLength, unordered_set<string> & visited, const int & k, string & sequence){
        if(sequence.length() == targetLength) return true;
        visited.insert(password);
        
        string password_suffix = password.substr(1);
        for(int i=0; i<k; i++){
            string nextPassword = password_suffix+string(1, '0'+i);
            if(visited.count(nextPassword)) continue;
            sequence.push_back('0'+i);
            bool res = dfs(nextPassword, targetLength, visited, k, sequence);
            if(res) return true;
            sequence.pop_back();
        }
        visited.erase(password);
        return false;
    }
    
    string crackSafe(int n, int k) {
        string password = string(n, '0');
        string sequence = password;
        int targetLength = pow(k, n)+n-1;
        unordered_set<string> visited;
        dfs(password, targetLength, visited, k, sequence);
        return sequence;
    }
};