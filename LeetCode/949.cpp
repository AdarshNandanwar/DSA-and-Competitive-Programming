// https://leetcode.com/problems/largest-time-for-given-digits/

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        multiset<int> s;
        for(auto i:A) s.insert(i);
        for(int i = 2; i>=0; i--){
            if(s.count(i)){
                s.erase(s.find(i));
                for(int j = (i==2 ? 3 : 9); j>=0; j--){
                    if(s.count(j)){
                        s.erase(s.find(j));
                        for(int k = 5; k>=0; k--){
                            if(s.count(k)){
                                s.erase(s.find(k));
                                return to_string(i)+to_string(j)+":"+to_string(k)+to_string(*s.begin());
                                s.insert(k);
                            }
                        }
                        s.insert(j);
                    }
                }
                s.insert(i);
            }
        }
        return "";
    }
};