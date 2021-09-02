// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

// Method 1 (istringstream):

class Solution {
public:
    
    bool helper(istringstream & iss){
        string s;
        if(!getline(iss, s, ',')) return false;
        if(s == "#") return true;
        else return helper(iss) and helper(iss);
    }
    
    bool isValidSerialization(string preorder) {
        istringstream iss(preorder);
        string s;
        return helper(iss) and !getline(iss, s, ',');
    }
};