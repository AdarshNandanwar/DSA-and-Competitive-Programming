// https://leetcode.com/problems/move-pieces-to-obtain-a-string/

// Method 1 (2 Pointer, O(n)):

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();

        int p1 = 0, p2 = 0;
        while(p1 < n and p2 < n){
            while(p1 < n and start[p1] == '_'){
                p1++;
            }
            while(p2 < n and target[p2] == '_'){
                p2++;
            }
            if(start[p1] != target[p2]){
                return false;
            }
            p1++;
            p2++;
        }
        while(p1 < n and start[p1] == '_'){
            p1++;
        }
        while(p2 < n and target[p2] == '_'){
            p2++;
        }
        if(p1 < n or p2 < n){
            return false;
        }

        int leftDelta = 0, rightDelta = 0;
        for(int i=0; i<n; i++){
            if(target[i] == 'L'){
                leftDelta++;
            }
            if(start[i] == 'L'){
                leftDelta--;
            }
            if(leftDelta < 0){
                return false;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(target[i] == 'R'){
                rightDelta++;
            }
            if(start[i] == 'R'){
                rightDelta--;
            }
            if(rightDelta < 0){
                return false;
            }
        }

        return true;
    }
};
