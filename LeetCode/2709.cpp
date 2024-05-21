// https://leetcode.com/problems/greatest-common-divisor-traversal

// Method 1 (Union Find, Sieve of Eratosthenes , O(MAX*loglog(MAX) + n*(n/logn) + n*logn)):

class Solution {
    void getPrimes(int n, vector<int>& outPrimes){
        vector<bool> sieve(n+1, true);
        for(long i=2; i*i<=n; i++){
            if(sieve[i] == false){
                continue;
            }
            for(long j=i*i; j<=n; j+=i){
                sieve[j] = false;
            }
        }
        
        for(int i=2; i<=n; i++){
            if(sieve[i] == true){
                outPrimes.push_back(i);
            }
        }
    }

    int getRoot(int r, vector<int>& root){
        if(root[r] == r){
            return r;
        }
        return root[r] = getRoot(root[r], root);
    }
    void merge(int r1, int r2, vector<int>& root){
        r1 = getRoot(r1, root);
        r2 = getRoot(r2, root);
        if(r1 != r2){
            root[r1] = r2;
        }
    }
public:
    bool canTraverseAllPairs(vector<int>& nums) {

        int minValue = *min_element(nums.begin(), nums.end());
        int maxValue = *max_element(nums.begin(), nums.end());
        if(minValue == 1){
            return nums.size() == 1;
        }

        // Optimization: Unique
        unordered_set<int> s(nums.begin(), nums.end());
        nums.clear();
        for(auto num:s){
            nums.push_back(num);
        }
        int n = nums.size();
        
        // Sieve of Eratosthenes, O(MAX*loglog(MAX)
        vector<int> primes;
        getPrimes(maxValue, primes);

        // Union Find, O(n*(n/logn))
        vector<int> root(maxValue+1);
        for(int i=0; i<maxValue+1; i++){
            root[i] = i;
        }
        for(int num:nums){
            for(int prime:primes){
                if(num % prime == 0){
                    merge(prime, num, root);
                }
                if(prime > num/2){
                    break;  // Optimization: Early break
                }
            }
        }
        
        // O(n*logn)
        for(int i=0; i<n; i++){
            if(getRoot(nums[0], root) != getRoot(nums[i], root)){
                return false;
            }
        }
        return true;
    }
};