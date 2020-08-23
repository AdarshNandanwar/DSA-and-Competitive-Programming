// https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/

// Method 1 (Hash Map, O(n)):

string Solution::solve(string A) {
    int p1 = 0, n = A.length();
    if(n == 0) return "";
    unordered_map<char, int> m;
    string B = "";
    for(int i = 0; i<n; i++){
        m[A[i]]++;
        while(p1<=i and m[A[p1]] > 1) p1++;
        if(p1 > i) B.push_back('#');
        else B.push_back(A[p1]);
    }
    return B;
}
