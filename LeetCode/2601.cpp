// https://leetcode.com/problems/prime-subtraction-operation/

// Method 1 (Sieve of Eratosthenes + Binary Search, O(nlogn + nloglogn)):

class Solution {
    void getPrimes(int n, set<int> & primes){
        vector<bool> isPrime(n+1, true);
        isPrime[0] = isPrime[1] = false;
        for(int i=2; i*i<=n; i++){
            if(isPrime[i] == false){
                continue;
            }
            for(int j=i*i; j<=n; j+=i){
                isPrime[j] = false;
            }
        }
        for(int i=2; i<=n; i++){
            if(isPrime[i]){
                primes.insert(i);
            }
        }
    }
public:
    bool primeSubOperation(vector<int>& nums) {
        set<int> primes;
        int maxValue = *max_element(nums.begin(), nums.end());
        getPrimes(maxValue, primes);

        int n = nums.size();
        int prevValue = 0;

        // subtract the max prime value you can at every time as you can subtract only once.
        for(int i=0; i<n; i++){
            int maxDiff = nums[i] - prevValue - 1;

            // Subtract max prime (if you can)
            auto ub = primes.upper_bound(maxDiff);
            if(ub != primes.begin()){
                int diff = *(prev(ub));
                nums[i] -= diff;
            }

            if(prevValue >= nums[i]){
                return false;
            }

            prevValue = nums[i];
        }

        return true;
    }
};
