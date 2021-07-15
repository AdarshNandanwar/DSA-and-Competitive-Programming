// https://www.interviewbit.com/problems/reverse-the-string/

string Solution::solve(string A) {
    istringstream ss(A);
    string s, res = "";
    while(getline(ss, s, ' ')){
        if(s == "") continue;
        if(res == "") res = s;
        else res = (s+" ")+res;
    }
    return res;
}
