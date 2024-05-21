// https://leetcode.com/problems/compare-version-numbers/

// Method 1 (IStringStream, O(n)):

class Solution {
public:
    int compareVersion(string version1, string version2) {
        string rev1, rev2;
        auto iss1 = istringstream(version1);
        auto iss2 = istringstream(version2);
        while(true){
            if(getline(iss1, rev1, '.')){
                if(getline(iss2, rev2, '.')){
                    int intRev1 = stoi(rev1);
                    int intRev2 = stoi(rev2);
                    if(intRev1 == intRev2){
                        continue;
                    } else {
                        return intRev1 > intRev2 ? 1 : -1;
                    }
                } else {
                    if(stoi(rev1) != 0){
                        return 1;
                    }
                    while(getline(iss1, rev1, '.')){
                        if(stoi(rev1) != 0){
                            return 1;
                        }
                    }
                    return 0;
                }
            } else {
                while(getline(iss2, rev2, '.')){
                    if(stoi(rev2) != 0){
                        return -1;
                    }
                }
                return 0;
            }
        }
        return 0;
    }
};

// Alternate Code:

class Solution {
public:
    
    void removeLeadingZeros(string & s){
        int i = 0;
        while(i<s.length() and s[i] == '0') i++;
        s = s.substr(i);
    }
    
    int compareVersion(string A, string B) {
        long long na, nb;
        string a, b;
        istringstream issa(A), issb(B);
        while(1){
            if(getline(issa, a, '.')){
                if(getline(issb, b, '.')){
                    removeLeadingZeros(a);
                    removeLeadingZeros(b);
                    if(a != b){
                        if(a.length() == b.length()){
                            return a > b ? 1: -1;
                        } else {
                            return a.length() > b.length() ? 1 : -1;
                        }
                    }
                } else {
                    if(a == "0"){
                        while(getline(issa, a, '.')){
                            removeLeadingZeros(a);
                            if(a.length()) return 1;
                        }
                        return 0;
                    } else {
                        return 1;
                    }
                }
            } else {
                if(getline(issb, b, '.')){
                    if(b == "0"){
                        while(getline(issb, b, '.')){
                            removeLeadingZeros(b);
                            if(b.length()) return -1;
                        }
                        return 0;
                    } else {
                        return -1;
                    }
                } else {
                    return 0;
                }
            }
        }
    }
};