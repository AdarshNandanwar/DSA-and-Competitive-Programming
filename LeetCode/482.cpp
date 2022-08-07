// https://leetcode.com/problems/license-key-formatting/

// Method 1 (O(n)):

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = s.length(), charCount=0;
        string res = "";
        for(int i=n-1; i>=0; i--){
            char c=s[i];
            if(c == '-') continue;
            if(res.length() and charCount%k == 0) res += '-';
            res += toupper(c);
            charCount++;
        }
        return string(res.rbegin(), res.rend());
    }
};

// Method 2 (O(n)):

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        for(auto &c:s){
            if(isalpha(c) and islower(c)) c += ('A'-'a');
        }
        
        string sNoDash = "", group = "", res = "";
        
        istringstream iss(s);
        while(getline(iss, group, '-')){
            sNoDash += group;
        }
        
        int n = sNoDash.length();
        int firstGroupSize = n%k;
        if(firstGroupSize){
            res = sNoDash.substr(0, firstGroupSize)+"-";
        }
        
        int groupCount = n/k;
        for(int i=0; i<groupCount; i++){
            res += (sNoDash.substr(firstGroupSize+i*k, k)+"-");
        }
        if(res.length()){
            res.pop_back();
        }
        
        return res;
    }
};