// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/

// Method 1 (O(n*m)):

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size(), m = bank[0].size();
        int prevCount = 0;
        int lasers = 0;
        for(int i=0; i<n; i++){
            int curCount = 0;
            for(int j=0; j<m; j++){
                curCount += (bank[i][j]-'0');
            }
            if(curCount > 0){
                lasers += (prevCount*curCount);
                prevCount = curCount;                
            }
        }
        return lasers;
    }
};