// https://www.interviewbit.com/problems/subarray-with-given-xor/

// Method 1 (Hash Table, O(n)):

int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> m;
    int cur = 0, res = 0;
    m[0] = 1;
    for(auto i:A){
        cur ^= i;
        if(m.count(cur^B)) res += m[cur^B];
        m[cur]++;
    }
    return res;
}
