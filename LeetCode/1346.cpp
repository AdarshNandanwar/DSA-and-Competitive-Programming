// https://leetcode.com/problems/check-if-n-and-its-double-exist/

// Method 1 (Hash set, O(n)):

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for(auto num:arr){
            if(num % 2 == 0 and s.count(num / 2)){
                return true;
            }
            
            if(s.count(num * 2)){
                return true;
            }

            s.insert(num);
        }

        return false;
    }
};
