// https://www.interviewbit.com/problems/pairs-with-given-xor/

// Method 1 (XOR, Hash Table, O(n)):

int Solution::solve(vector<int> &A, int B) {
    int res = 0;
    unordered_map<int, int> m;
    for(auto i:A){
        if(m.count(i^B)) res += m[i^B];
        m[i]++;
    }
    return res;
}
