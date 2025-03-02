// https://leetcode.com/problems/maximum-swap/

// Method 1 (Greedy, O(n)):

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        int swapIndex1 = -1;
        int swapIndex2 = -1;
        
        char largestDigit = s[n-1];
        int largestDigitIndex = n-1;
        for(int i=n-2; i>=0; i--){
            if(largestDigit < s[i]){
                largestDigit = s[i];
                largestDigitIndex = i;
            } else if(s[i] < largestDigit){
                swapIndex1 = i;
                swapIndex2 = largestDigitIndex;
            }
        }
        
        if(swapIndex1 != -1){
            swap(s[swapIndex1], s[swapIndex2]);
            return stoi(s);
        }

        return num;
    }
};

// Method 1 (Greedy, O(n2)):

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        for(int i=0; i<n; i++){
            char nextGreater = s[i];
            for(int j=i+1; j<n; j++){
                if(s[j] > nextGreater){
                    nextGreater = s[j];
                }
            }
            if(nextGreater == s[i]){
                continue;
            }

            string maxString = s;
            for(int j=i+1; j<n; j++){
                if(s[j] == nextGreater){
                    string candidate = s;
                    swap(candidate[i], candidate[j]);
                    maxString = max(maxString, candidate);
                }
            }
            return stoi(maxString);
        }
        
        return num;
    }
};
