// https://leetcode.com/problems/verifying-an-alien-dictionary/

// Method 1 (Comparator):

class Solution {
public:
    
    bool cmp(const string & a, const string & b, const string & order){
        int la = a.length(), lb = b.length();
        for(int i = 0; i<min(la, lb); i++){
            auto pa = order.find(a[i]);
            auto pb = order.find(b[i]);
            if(pa != pb) return pa < pb;
        }
        return la <= lb;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i<words.size()-1; i++){
            if(!cmp(words[i], words[i+1], order)) return false;
        }
        return true;
    }
};

// Method 2:

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i<words.size()-1; i++){
            int l1 = words[i].length(), l2 = words[i+1].length(), equal = 1;
            for(int j = 0; j<min(l1, l2); j++){
                auto p1 = order.find(words[i][j]);
                auto p2 = order.find(words[i+1][j]);
                if(p1 > p2) return false;
                if(p1 < p2){
                    equal = 0;
                    break;
                }
            }
            if(equal and l1 > l2) return false;
        }
        return true;
    }
};