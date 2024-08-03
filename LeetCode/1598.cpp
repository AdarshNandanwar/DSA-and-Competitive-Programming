// https://leetcode.com/problems/crawler-log-folder/

// Method 1 (O(n)):

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for(const string & log:logs){
            if(log == "../"){
                if(depth > 0){
                    depth--;
                }
            } else if (log == "./"){
                continue;
            } else {
                depth++;
            }
        }
        return depth;
    }
};
