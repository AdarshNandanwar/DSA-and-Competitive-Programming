// https://leetcode.com/problems/count-number-of-teams/

// Method 1 (Suffix Pre-Computation, O(n2)):)

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

// Method 2 (Brute Force, TLE, O(n3)):

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