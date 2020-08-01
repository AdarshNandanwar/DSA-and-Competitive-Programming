// https://www.interviewbit.com/problems/minimum-parantheses/

int Solution::solve(string A) {
    int open = 0, openAdded = 0;
    for(auto i:A){
        if(i == '('){
            open++;
        } else {
            if(open == 0) openAdded++;
            else open--;
        }
    }
    return openAdded+open;
}
