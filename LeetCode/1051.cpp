// https://leetcode.com/problems/height-checker/

// Method 1 (Counting Sort, O(n)):

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> freq(101);
        int n = heights.size(), count = 0;
        for(int i=0; i<n; i++){
            freq[heights[i]]++;
        }
        int currentHeight = 1;
        for(int i=0; i<n; i++){
            while(freq[currentHeight] == 0){
                currentHeight++;
            }
            freq[currentHeight]--;
            if(heights[i] != currentHeight){
                count++;
            }
        }
        
        return count;
    }
};

// Method 2 (Merge Sort, O(nlogn)):

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sh(heights.begin(), heights.end());
        sort(sh.begin(), sh.end());
        int count = 0;
        for(int i = 0; i<sh.size(); i++) count += (sh[i]!=heights[i]);
        return count;
    }
};
