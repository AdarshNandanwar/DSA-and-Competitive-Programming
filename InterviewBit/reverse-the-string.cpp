// https://www.interviewbit.com/problems/reverse-the-string/

string Solution::solve(string A) {
    string res  = "", w;
    istringstream iss(A);
    while(getline(iss, w ,' ')) if(w.length()) res = w+" "+res;
    if(res.length()) res.pop_back();
    return res;
}
