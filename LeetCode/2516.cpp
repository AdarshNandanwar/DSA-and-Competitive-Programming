// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/

// Method 1 (Binary Search, O(nlogn)):

class Solution {
    bool predicate(const string & v, const int k, int mid){
        unordered_map<char, int> freq;
        int n = v.size();
        mid = min(n, mid);

        int count = 0;
        for(int i=0; i<mid; i++){
            freq[v[i]]++;
            if(freq[v[i]] == k){
                count++;
            }
        }
        if(count == 3){
            return true;
        }

        for(int i=mid-1; i>=0; i--){
            if(freq[v[i]] == k){
                count--;
            }
            freq[v[i]]--;
            freq[v[n-mid+i]]++;
            if(freq[v[n-mid+i]] == k){
                count++;
            }
            if(count == 3){
                return true;
            }
        }
        return false;
    }
public:
    int takeCharacters(string s, int k) {
        if(k == 0) {
            return 0;
        }

        int n = s.length();
        unordered_set<char> ss(s.begin(), s.end());
        int distinctCount = ss.size();

        // FT First T
        int hi = n, lo = 1;
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(predicate(s, k, mid)){
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        if(predicate(s, k, lo)){
            return lo;
        } else {
            return -1;
        }
    }
};
