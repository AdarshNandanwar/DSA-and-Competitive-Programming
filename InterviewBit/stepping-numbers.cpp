// https://www.interviewbit.com/problems/stepping-numbers/

bool isStepping(int n){
    int prev = n%10;
    n/=10;
    while(n){
        if(abs(prev - n%10) != 1) return false;
        prev = n%10;
        n/=10;
    }
    return true;
}

vector<int> Solution::stepnum(int A, int B) {
    vector<int> res;
    for(int i = A; i<=B; i++){
        if(isStepping(i)) res.push_back(i);
    }
    return res;
}
