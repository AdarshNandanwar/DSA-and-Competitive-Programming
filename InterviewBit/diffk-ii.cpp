// https://www.interviewbit.com/problems/diffk-ii/

// Method 1 (Hash Table, O(n)):

int Solution::diffPossible(const vector<int> &A, int B) {
    unordered_set<int> s;
    for(auto i:A){
        if(s.count(i-B) or s.count(i+B)) return 1;
        s.insert(i);
    }
    return 0;
}