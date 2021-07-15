// https://www.interviewbit.com/problems/add-binary-strings/

string Solution::addBinary(string A, string B) {
    if(A.length() < B.length()) swap(A, B);
    string s = "";
    int i = A.length()-1, j = B.length()-1, carry = 0, sum = 0;
    while(i>=0 and j>=0){
        sum = A[i--]-'0'+B[j--]-'0'+carry;
        s.push_back(sum%2+'0');
        carry = sum/2;
    }
    while(i>=0){
        sum = A[i--]-'0'+carry;
        s.push_back(sum%2+'0');
        carry = sum/2;
    }
    if(carry) s.push_back(carry+'0');
    return string(s.rbegin(), s.rend());
}
