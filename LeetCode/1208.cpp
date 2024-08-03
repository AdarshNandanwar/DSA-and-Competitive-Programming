// https://leetcode.com/problems/get-equal-substrings-within-budget/

// Method 1 (Sliding Window, O(n)):

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();        
        int maxLength = 0;
        // Sliding window [p1, p2)]
        int p1 = n-1, p2 = n, curCost = 0;
        while(p1>=0){
            curCost += abs(s[p1]-t[p1]);
            while(curCost > maxCost){
                curCost -= abs(s[p2-1]-t[p2-1]);
                p2--;
            }
            maxLength = max(maxLength, p2-p1);
            p1--;
        }
        return maxLength;
    }
};

// Method 2 (Binary Search, O(nlogn)):

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int maxLength = 0;
        // suffixCost[i] = cost to change s[i..n-1] to t[i..n-1]
        vector<int> suffixCost(n+1);
        for(int i=n-1; i>=0; i--){
            suffixCost[i] = abs(s[i]-t[i]) + suffixCost[i+1];
            int target = suffixCost[i] - maxCost;
            
            // Binary Search
            // suffixCost[mid] >= target
            // TF Last T
            int lo = i, hi = n;
            while(lo<hi){
                int mid = lo+(hi-lo+1)/2;
                if(suffixCost[mid] >= target){
                    lo = mid;
                } else {
                    hi = mid-1;
                }
            }

            if(suffixCost[lo] >= target){
                maxLength = max(maxLength, lo-i);
            }
        }
        
        return maxLength;
    }
};
