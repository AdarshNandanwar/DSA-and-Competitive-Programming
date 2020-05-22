// https://leetcode.com/problems/subarrays-with-k-different-integers/

class Solution {
public:
    
    int subarraysWithAtmostKDistinct(vector<int>& A, int K) {
        int n = A.size();
        unordered_map<int, int> m;
        
        // p2 is always 1 ahead of the window
        // p1 is the start of the window
        // ie. [p1, p2)
        // at the end of each iteration, we add the number of subarrays ending at p2-1
        // ie. the last element of the current window
        
        int p1 = 0, p2 = 0, distinct = 0;
        long long int ans = 0;
        while(p2<n){
            
            m[A[p2]]++;
            if(m[A[p2]] == 1)
                distinct++;
            p2++;
            
            while(p1<p2 && distinct>K){
                m[A[p1]]--;
                if(m[A[p1]] == 0)
                    distinct--;
                p1++;
            }
            
            // adding number of subarrays ending at index p2-1
            ans += (p2-p1);
            
        }
        
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return subarraysWithAtmostKDistinct(A, K) - subarraysWithAtmostKDistinct(A, K-1);
    }
};