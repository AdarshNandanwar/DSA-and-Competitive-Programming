// https://www.interviewbit.com/problems/letter-phone/

void helper(const string & A, int index, vector<string> & m, string cur, vector<string> & res){
    if(index == A.length()){
        res.push_back(cur);
        return;
    }
    for(auto i:m[A[index]-'0']) helper(A, index+1, m, cur+string(1, i), res);
}

vector<string> Solution::letterCombinations(string A) {
    vector<string> m(10);
    m[0] = "0";
    m[1] = "1";
    m[2] = "abc";
    m[3] = "def";
    m[4] = "ghi";
    m[5] = "jkl";
    m[6] = "mno";
    m[7] = "pqrs";
    m[8] = "tuv";
    m[9] = "wxyz";
    vector<string> res;
    helper(A, 0, m, "", res);
    return res;
}
