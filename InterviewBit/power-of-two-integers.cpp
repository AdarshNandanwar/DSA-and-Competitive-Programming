// https://www.interviewbit.com/problems/power-of-two-integers/

int Solution::isPower(int A) {
    unordered_map<int, int> dp;
    if(A == 1) return 1;
    for(int i = 2; i<=sqrt(A); i++){
        double l = log(A)/log(i);
        if(pow(i, floor(l)) == A) return 1;
    }
    return 0;
}
