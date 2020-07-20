// https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int height = 0, l = label;
        vector<int> ans;
        
        while(l){
            l = l>>1;
            height++;
        }
        
        // 3*(1<<(height-1))-x-1
        bool invert = false;
        
        while(label){
            if(invert) ans.push_back(3*(1<<(height-1))-label-1);
            else ans.push_back(label);
            label = label>>1;
            invert = !invert;
            height--;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};