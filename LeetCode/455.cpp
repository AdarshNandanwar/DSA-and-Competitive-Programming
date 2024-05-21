// https://leetcode.com/problems/assign-cookies/description/

// Method 1 (2 Pointer, Greedy, O(nlogn)):

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int childCount = g.size(), cookieCount = s.size();
        int childPointer = 0, cookiePointer = 0;
        int contentChildCount = 0;
        while(childPointer < childCount and cookiePointer < cookieCount){
            while(cookiePointer < cookieCount and g[childPointer] > s[cookiePointer]){
                cookiePointer++;
            }
            if(cookiePointer == cookieCount){
                break;
            }
            contentChildCount++;
            childPointer++;
            cookiePointer++;
        }
        return contentChildCount;
    }
};
