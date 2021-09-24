// https://leetcode.com/problems/slowest-key/

// Method 1 (O(n)):

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = keysPressed.length(), max_dur = releaseTimes[0];
        char res = keysPressed[0];
        for(int i = 1; i<n; i++){
            int dur = releaseTimes[i]-releaseTimes[i-1];
            if(max_dur < dur or (max_dur == dur and res < keysPressed[i])){
                max_dur = dur;
                res = keysPressed[i];
            }
        }
        return res;
    }
};