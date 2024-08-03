// https://leetcode.com/problems/count-number-of-teams/

// Method 0 (Fenwick Tree, O(nlog(maxRating)) time, O(maxRating) space):

class Solution {

    // Fenwick Tree Methods
    void insert(vector<int> & bit, int index, int val){
        index++;
        for(int i=index; i<bit.size(); i += (i&(-i))){
            bit[i] += val;
        }
    }
    void remove(vector<int> & bit, int index, int val){
        index++;
        for(int i=index; i<bit.size(); i += (i&(-i))){
            bit[i] -= val;
        }
    }
    int getPrefixSum(vector<int> & bit, int index){
        index++;
        int sum = 0;
        for(int i=index; i>0; i -= (i&(-i))){
            sum += bit[i];
        }
        return sum;
    }
    int getRangeSum(vector<int> & bit, int st, int end){ // inclusive
        return getPrefixSum(bit, end) - getPrefixSum(bit, st-1);
    }

    // Solve for increasing triplets
    int countIncreasing(const vector<int> & rating){
        int n = rating.size(), teams = 0;
        int maxElement = *max_element(rating.begin(), rating.end());

        // Fenwick Tree
        vector<int> rightBit(maxElement + 2);
        vector<int> leftBit(maxElement + 2);

        for(int i=1; i<n; i++){
            insert(rightBit, rating[i], 1);
        }

        for(int i=1; i<n-1; i++){
            remove(rightBit, rating[i], 1);
            insert(leftBit, rating[i-1], 1);
            int countGreater = getRangeSum(rightBit, rating[i]+1, maxElement);
            int countLower = getRangeSum(leftBit, 1, rating[i]-1);
            teams += (countLower * countGreater);
        }

        return teams;
    }
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        ans += countIncreasing(rating);
        reverse(rating.begin(), rating.end());
        ans += countIncreasing(rating);
        return ans;
    }
};

// Method 1 (Loops, O(n2) time, O(1) space):

class Solution {
    int countIncreasing(const vector<int> & rating){
        int n = rating.size(), teams = 0;
        for(int mid = 1; mid < n-1; mid++){
            int lesserCount = 0;
            int greaterCount = 0;
            for(int i=0; i<mid; i++){
                if(rating[i] < rating[mid]){
                    lesserCount++;
                }
            }
            for(int i=mid+1; i<n; i++){
                if(rating[mid] < rating[i]){
                    greaterCount++;
                }
            }
            teams += (lesserCount * greaterCount);
        }
        return teams;
    }
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        ans += countIncreasing(rating);
        reverse(rating.begin(), rating.end());
        ans += countIncreasing(rating);
        return ans;
    }
};

// Method 2 (Suffix Pre-Computation, O(n2) time, O(n) space):

class Solution {
    int countIncreasing(const vector<int> & rating){
        int n = rating.size();
        // countGreater[i] = number of values in rating[i+1, n) that are strictly greater than countGreater[i]
        vector<int> countGreater(n, 0);
        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(rating[i] < rating[j]){
                    countGreater[i]++;
                }
            }
        }
        int teams = 0;
        for(int i=n-3; i>=0; i--){
            for(int j=i+1; j<n-1; j++){
                if(rating[i] < rating[j]){
                    teams += countGreater[j];
                }
            }
        }
        return teams;
    }
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        ans += countIncreasing(rating);
        reverse(rating.begin(), rating.end());
        ans += countIncreasing(rating);
        return ans;
    }
};

// Alternate Code:

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<int> nextGreaterCount(n, 0);
        vector<int> nextLesserCount(n, 0);
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(rating[i] < rating[j]) nextGreaterCount[i]++;
                if(rating[i] > rating[j]) nextLesserCount[i]++;
            }
        }
        int res = 0;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(rating[i] < rating[j]) res += nextGreaterCount[j];
                if(rating[i] > rating[j]) res += nextLesserCount[j];
            }
        }
        return res;
    }
};

// Method 3 (Brute Force, TLE, O(n3)):

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), res = 0;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                for(int k = j+1; k<n; k++){
                    if(rating[i] < rating[j] and rating[j] < rating[k]) res++;
                    if(rating[i] > rating[j] and rating[j] > rating[k]) res++;
                }
            }
        }
        return res;
    }
};