// https://www.interviewbit.com/problems/excel-column-title/

string Solution::convertToTitle(int A) {
    string res = "";
    while(A){
        res = string(1, 'A'+(A-1)%26) + res;
        A = (A-1)/26;
    }
    return res;
}
