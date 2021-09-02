// https://www.interviewbit.com/problems/multiply-strings/

// Method 1 (Optimized, O(la*lb)):

string Solution::multiply(string A, string B) {
    int carry = 0, la = A.length(), lb = B.length(), k, i;
    string res(la+lb, '0');
    for(i = lb-1; i>=0; i--){
        carry = 0;
        for(int j = la-1; j>=0; j--){
            k = (res[i+j+1]-'0')+(B[i]-'0')*(A[j]-'0')+carry;
            res[i+j+1] = k%10+'0';
            carry = k/10;
        }
        if(carry) res[i] += carry;
    }
    for(i = 0; i<la+lb; i++) if(res[i] != '0') return res.substr(i);
    return "0";
}

// Method 2 (Nursery Method, O(la*lb)):

string add(string a, string b){
    if(a.length() < b.length()) swap(a, b);
    int carry = 0, la = a.length(), lb = b.length();
    int i = la-1, j = lb-1;
    string res = "";
    while(i>=0 and j>=0){
        int sum = a[i]-'0'+b[j]-'0'+carry;
        res.push_back((sum%10)+'0');
        carry = sum/10;
        i--;
        j--;
    }
    while(i>=0){
        int sum = a[i]-'0'+carry;
        res.push_back((sum%10)+'0');
        carry = sum/10;
        i--;
    }
    if(carry) res.push_back(carry+'0');
    reverse(res.begin(), res.end());
    i = 0;
    while(i<res.length() and res[i] == '0') i++;
    res = res.substr(i);
    return res == "" ? "0" : res;
}

string Solution::multiply(string A, string B) {
    int carry = 0, la = A.length(), lb = B.length(), k;
    
    string res = "0";
    for(int i = lb-1; i>=0; i--){
        string temp = string(lb-i-1, '0');
        carry = 0;
        for(int j = la-1; j>=0; j--){
            k = (B[i]-'0')*(A[j]-'0')+carry;
            temp.push_back((k%10)+'0');
            carry = k/10;
        }
        if(carry) temp.push_back(carry+'0');
        reverse(temp.begin(), temp.end());
        res = add(res, temp);
    }
    return res;
}
