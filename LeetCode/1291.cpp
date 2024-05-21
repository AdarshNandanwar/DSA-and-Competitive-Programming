// https://leetcode.com/problems/sequential-digits/

// Method 1 (Brute Force, O(1)):

class Solution {
    void helper(int cur, const int low, const int high, vector<int>& ans){
        if(low <= cur and cur <= high){
            ans.push_back(cur);
        }

        int prevDigit = cur%10;
        if(prevDigit == 9){
            return;
        }

        helper(cur*10 + prevDigit+1, low, high, ans);
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int startDigit = 1; startDigit < 10; startDigit++){
            helper(startDigit, low, high, ans);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// Method 2 (Substring Trick, O(1)):

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string increasingDigits = "123456789";
        int n = increasingDigits.length();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<=n; j++){
                // substring [i,j)
                int cur = stoi(increasingDigits.substr(i, j-i));
                if(low <= cur and cur <= high){
                    ans.push_back(cur);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// Method 3 (Recursion, O(1)):

class Solution {
    void helper(int place, int cur, const int low, const int high, vector<int>& ans){
        if(place == 0){
            ans.push_back(cur);
            return;
        }

        int prevDigit = cur%10;
        if(prevDigit == 9){
            return;
        }
        
        int lowPrefix = low/place;
        int highPrefix = high/place;
        if(prevDigit == 0){
            for(int startDigit = 0; startDigit<10; startDigit++){
                int next = cur*10 + startDigit;
                if(lowPrefix <= next and next <= highPrefix){
                    helper(place/10, next, low, high, ans);
                }
            }
        } else if(prevDigit < 9){
            int next = cur*10 + prevDigit+1;
            if(lowPrefix <= next and next <= highPrefix){
                helper(place/10, next, low, high, ans);
            }
        }
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        int len = to_string(high).length();
        vector<int> ans;
        helper(pow(10, len-1), 0, low, high, ans);
        return ans;
    }
};