// https://www.interviewbit.com/problems/largest-number/

string Solution::largestNumber(const vector<int> &A) {
    vector<string> v;
    bool zero = 1;
    for(auto &i:A){
        v.push_back(to_string(i));
        if(i) zero = 0;
    } 
    if(zero) return "0";
    sort(v.begin(), v.end(), [](const string & a, const string & b){
        return a+b>b+a;
    });
    string s = "";
    for(auto &i:v) s += i;
    return s;
}
