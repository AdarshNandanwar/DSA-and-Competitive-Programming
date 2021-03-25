// https://www.interviewbit.com/problems/colorful-number/

// Method 1 (Hash Table):

int Solution::colorful(int A) {
    string s = to_string(A);
    int n = s.size();
    if(n <= 1) return 1;
    // set of product of digits of all subarrays
    unordered_set<int> m;
    // v[i] : set of product of digits of all subarrays ending at index i
    vector<unordered_set<int>> v(n);
    m.insert(s[0]-'0');
    v[0].insert(s[0]-'0');
    for(int i = 1; i<n; i++){
        if(m.count(s[i]-'0')) return 0;
        m.insert(s[i]-'0');
        for(auto j:v[i-1]) {
            if(m.count(j*(s[i]-'0'))) return 0;
            m.insert(j*(s[i]-'0'));
            v[i].insert(j*(s[i]-'0'));
        }
    }
    return 1;
}
