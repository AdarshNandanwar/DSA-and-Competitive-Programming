// https://leetcode.com/problems/video-stitching/

// Method 1 (implicit BST, O(n)):

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        
        int n = clips.size();
        if(n == 0 or T == 0) return 0;
        
        // Similar to Jump Game II
        // implicit BFS
        
        unordered_map<int, int> maxRight;
        
        for(auto c:clips) maxRight[c[0]] = max(maxRight[c[0]], c[1]);
        
        int curEnd = 0, maxChildEnd = 0, count = 0;
        for(int i = 0; i<=T; i++){
            maxChildEnd = max(maxChildEnd, maxRight[i]);
            if(maxChildEnd >= T) return count+1;
            if(i == curEnd){
                if(curEnd == maxChildEnd) return -1;
                curEnd = maxChildEnd;
                count++;
            }
        }
        
        return -1;
    }
};

// Method 1 (implicit BST, O(nlogn)):

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        
        int n = clips.size();
        if(n == 0 or T == 0) return 0;
        
        // Similar to Jump Game II
        // implicit BFS
        
        sort(clips.begin(), clips.end(), [](const vector<int> & a, const vector<int> & b){
            return a[0]<b[0];
        });
        
        int curEnd = 0, maxChildEnd = 0, index = 0, count = 0;
        for(int i = 0; i<=T; i++){
            while(index < n and clips[index][0] == i){
                maxChildEnd = max(maxChildEnd, clips[index][1]);
                index++;
            }
            if(maxChildEnd >= T) return count+1;
            if(i == curEnd){
                if(curEnd == maxChildEnd) return -1;
                curEnd = maxChildEnd;
                count++;
            }
        }
        
        return -1;
    }
};