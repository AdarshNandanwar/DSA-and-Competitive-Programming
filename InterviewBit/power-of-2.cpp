// https://www.interviewbit.com/problems/power-of-2/

bool helper(const string & A){
    if(A == "1") return 1;
    int n = A.length(), div = 0, r = 0;
    string q = "";
    for(int i = 0; i<n; i++){
        div = r*10 + (A[i]-'0');
        if(!(q == "" and (div/2) == 0)) q.push_back((div/2)+'0');
        r = div%2;
    }
    if(r != 0) return 0;
    return helper(q);
}

int Solution::power(string A) {
    if(A == "" or A == "0" or A == "1") return 0;
    return helper(A);
}
