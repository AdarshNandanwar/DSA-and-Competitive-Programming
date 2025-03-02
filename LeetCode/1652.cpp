// https://leetcode.com/problems/defuse-the-bomb/

// Method 1 (Loops, O(n2)):

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> decrypted(n);

        if(k == 0){
            return decrypted;
        }

        for(int i=0; i<n; i++){
            if(k > 0){
                for(int j=1; j<=k; j++){
                    decrypted[i] += code[(i+j)%n];
                }
            } else {
                for(int j=1; j<=abs(k); j++){
                    decrypted[i] += code[(n+i-j)%n];
                }
            }
        }

        return decrypted;
    }
};
