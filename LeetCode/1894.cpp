// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/

// Method 1 (Modulo, O(n)):

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = 0;
        for(int ch:chalk){
            sum += ch;
        }
        k %= sum;
        for(int i=0; i<n; i++){
            if(chalk[i] > k){
                return i;
            }
            k -= chalk[i];
        }
        return 0;
    }
};
