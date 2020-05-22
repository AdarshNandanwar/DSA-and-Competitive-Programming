// https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n = A.size();
        if(n == 0){
            return 0;
        }
        unordered_map<int, long long int> m;
        vector<long long int> cumSum(n+1, 0);
        m[0]++;
        for(int i = 1; i<n+1; i++){
            cumSum[i] = cumSum[i-1]+A[i-1];
            m[(cumSum[i]%K < 0)?(cumSum[i]%K + K):(cumSum[i]%K)]++;
        } 
        
        long long int ans = 0;
        for(int i=0; i<K; i++){
            if(m[i]<2){
                continue;
            }
            ans += ((m[i]*(m[i]-1))/2);
        }
        
        return ans;
    }
};