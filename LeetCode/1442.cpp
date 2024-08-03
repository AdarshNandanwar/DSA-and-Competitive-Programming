// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/

// Method 1 (Optimizing method 2 logic to remove inner loop by storing sums, O(n) time, O(n) space):

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int count = 0;

        // Property: If an array has XOR = 0,
        // no matter how you partition it, both sides will have equal XOR.
        // Else, if you take their XOR, the result will not be 0.

        // So, we just need to detect all subarrays with XOR 0

        // indexSum[i] = sum of all indexes (not values at indexes) j for which XOR of [j..n) is i
        // indexCount[i] = count of indexes j for which XOR of [j..n) is i
        unordered_map<int, int> indexSum, indexCount;
        indexSum[0] = n;
        indexCount[0] = 1;
        int curXor = 0;
        for(int i=n-1; i>=0; i--){
            curXor ^= arr[i];
            count += (indexSum[curXor] - indexCount[curXor]*i - indexCount[curXor]);
            indexSum[curXor] += i;
            indexCount[curXor] += 1;
        }
        return count;
    }
};

// Method 2 (HashMap, O(n2) time, O(n2) space):

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int count = 0;

        // Property: If an array has XOR = 0,
        // no matter how you partition it, both sides will have equal XOR.
        // Else, if you take their XOR, the result will not be 0.

        // So, we just need to detect all subarrays with XOR 0

        unordered_map<int, unordered_set<int>> indexes;
        indexes[0].insert(n);
        int curXor = 0;
        for(int i=n-1; i>=0; i--){
            curXor ^= arr[i];
            for(int index:indexes[curXor]){
                count += (index-i-1);
            }
            indexes[curXor].insert(i);
        }
        return count;
    }
};

// Method 3 (Hash Map, O(n2) time, O(n2) space):

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        vector<unordered_map<int, int>> suffixXorFreq(n);
        for(int i=n-1; i>=0; i--){
            int curXor = 0;
            for(int j=i; j<n; j++){
                curXor ^= arr[j];
                suffixXorFreq[i][curXor]++;
            }
        }
        for(int i=1; i<n; i++){
            int curXor = 0;
            for(int j=i-1; j>=0; j--){
                curXor ^= arr[j];
                if(suffixXorFreq[i].count(curXor)){
                    count += suffixXorFreq[i][curXor];
                }
            }
        }
        return count;
    }
};

// Method 4 (Brute Force with Suffix XOR, O(n3) time, O(n) space):

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        vector<int> suffixXor(n+1);
        for(int i=n-1; i>=0; i--){
            suffixXor[i] = suffixXor[i+1] ^ arr[i];
        }
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j; k<n; k++){
                    if((suffixXor[i]^suffixXor[j]) == (suffixXor[j]^suffixXor[k+1])){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
