// https://www.interviewbit.com/problems/longest-substring-without-repeat/

int Solution::lengthOfLongestSubstring(string A) {
    unordered_map<int, int> freq;
    int p1 = 0, p2 = 0, n = A.length(), maxLen = 0;
    while(p2<n){
        while(freq[A[p2]]){
            freq[A[p1++]]--;
        }
        freq[A[p2]]++;
        maxLen = max(maxLen, p2-p1+1);
        p2++;
    }
    return maxLen;
}
