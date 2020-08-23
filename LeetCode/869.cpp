// https://leetcode.com/problems/reordered-power-of-2/

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        vector<int> freq(10, 0);
        int t = N, j;
        while(t){
            freq[t%10]++;
            t/=10;
        }
        for(long i = 1; i<=INT_MAX; i = i<<1){
            vector<int> curFreq(10, 0);
            t = i;
            while(t){
                curFreq[t%10]++;
                t/=10;
            }
            for(j = 0; j<10; j++) if(freq[j] != curFreq[j]) break;
            if(j == 10) return 1;
        }
        return 0;
    }
};