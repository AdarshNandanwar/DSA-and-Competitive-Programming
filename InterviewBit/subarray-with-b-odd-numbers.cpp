// https://www.interviewbit.com/problems/subarray-with-b-odd-numbers/

// Method 1 (Hash Table, O(n)):

int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> m;
    m[0] = 1;
    int oddCount = 0, res = 0;
    for(auto i:A){
        oddCount += (i&1);
        if(m.count(oddCount-B)) res += m[oddCount-B];
        m[oddCount]++;
    }
    return res;
}