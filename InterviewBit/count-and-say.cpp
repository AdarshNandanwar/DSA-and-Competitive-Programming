// https://www.interviewbit.com/problems/count-and-say/

string Solution::countAndSay(int A) {
    if(A == 1) return "1";
    string s = countAndSay(A-1), res = "";
    char cur;
    int count;
    for(int i = 0; i<s.length();){
        cur = s[i];
        count = 0;
        while(i<s.length() and cur == s[i]){
            count++; i++;
        }
        res += (to_string(count)+cur);
    }
    return res;
}
