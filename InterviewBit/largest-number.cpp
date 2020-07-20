// https://www.interviewbit.com/problems/largest-number/

bool cmp(const int & a, const int & b){
    string sa = to_string(a), sb = to_string(b);
    return sa+sb > sb+sa;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<int> v(A);
    sort(v.begin(), v.end(), cmp);
    string ans = "";
    for(auto i:v){
        if(ans.length() == 0 and i==0) continue;
        ans.append(to_string(i));
    } 
    return ans.length() == 0 ? "0" : ans;
}
