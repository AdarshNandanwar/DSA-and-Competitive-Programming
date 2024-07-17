// https://leetcode.com/problems/maximum-score-from-removing-substrings/

// Method 0 (See Leetcode, O(n) time, O(1) space):

// Method 1 (Greedy, String Stack, O(n) time, O(1) space):

class Solution {
    int countPatterns(string & s, const string pattern){
        int n = s.length();
        int count = 0;

        // Use string memory as stack
        int writeIndex = 0, readIndex = 0;
        while(readIndex < n){
            if(writeIndex > 0 and s[writeIndex - 1] == pattern[0] and s[readIndex] == pattern[1]){
                writeIndex--;
                readIndex++;
                count++;
            } else {
                s[writeIndex] = s[readIndex];
                readIndex++;
                writeIndex++;
            }
        }

        // Resize the string for further passes
        s = s.substr(0, writeIndex);

        return count;
    }
public:
    int maximumGain(string s, int x, int y) {
        string patternX = "ab";
        string patternY = "ba";

        int countX = 0, countY = 0;
        if(x > y){
            countX = countPatterns(s, patternX);
            countY = countPatterns(s, patternY);
        } else {
            countY = countPatterns(s, patternY);
            countX = countPatterns(s, patternX);
        }

        return (countX * x) + (countY * y);
    }
};

// Method 2 (Greedy Stack, O(n) time, O(n) space):

class Solution {
    int countInString(const string & s, stack<char> & st, const string pattern){
        int count = 0;
        for(char c:s){
            if(!st.empty() and st.top() == pattern[0] and c == pattern[1]){
                st.pop();
                count++;
            } else {
                st.push(c);
            }
        }
        return count;
    }
    int countInStack(stack<char> & st, const string pattern){
        int count = 0;
        stack<char> prev;
        while(!st.empty()){
            char cur = st.top();
            st.pop();
            if(cur == pattern[0] and !prev.empty() and prev.top() == pattern[1]){
                prev.pop();
                count++;
            } else {
                prev.push(cur);
            }
        }
        return count;
    }
public:
    int maximumGain(string s, int x, int y) {
        string patternX = "ab";
        string patternY = "ba";

        int countX = 0, countY = 0;
        stack<char> st;
        if(x > y){
            countX = countInString(s, st, patternX);
            countY = countInStack(st, patternY);
        } else {
            countY = countInString(s, st, patternY);
            countX = countInStack(st, patternX);
        }

        return (countX * x) + (countY * y);
    }
};
