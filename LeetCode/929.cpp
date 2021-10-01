// https://leetcode.com/problems/unique-email-addresses/

// Method 1 (O(n)):

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for(auto &email:emails){
            string temp = "";
            bool ignore = false, is_domain = false;
            for(int i = 0; i<email.length(); i++){
                if(email[i] == '@') is_domain = true;
                if(email[i] == '+') ignore = true;
                if(!is_domain and (ignore or email[i] == '.')) continue;
                temp.push_back(email[i]);
            }
            s.insert(temp);
        }
        return s.size();
    }
};