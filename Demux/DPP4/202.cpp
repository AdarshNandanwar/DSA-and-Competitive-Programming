// https://leetcode.com/problems/happy-number/

// Method 1 (Floyd's Cycle Detection Algorithm):

class Solution {
public:
    string getNext(string s){
        int next = 0;
        for(auto c:s){
            next += ((c-'0')*(c-'0'));
        }
        return to_string(next);
    }
    
    bool isHappy(int n) {
        string slow, fast;
        slow = fast = to_string(n);
        
        // Floyd's Cycle Detection Algorithm OR 2 pointer method
        do{
            slow = getNext(slow);
            fast = getNext(getNext(fast));
            if(slow == "1" or fast == "1") return true;
        } while(slow!=fast);
        return false;
    }
};

// Method 2 (Hash Set)

class Solution {
public:
    bool isHappy(int n) {
        string s = to_string(n);
        unordered_set<string> visited;
        while(visited.find(s) == visited.end() and s != "1"){
            visited.insert(s);
            int next = 0;
            for(auto c:s){
                next += ((c-'0')*(c-'0'));
            }
            s = to_string(next);
        }
        return s == "1";
    }
};