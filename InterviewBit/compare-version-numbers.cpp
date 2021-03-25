// https://www.interviewbit.com/problems/compare-version-numbers/

void removeLeadingZeros(string & s){
    int i = 0;
    while(i<s.length() and s[i] == '0') i++;
    s = s.substr(i);
}

int Solution::compareVersion(string A, string B) {
    long long na, nb;
    string a, b;
    istringstream issa(A), issb(B);
    while(1){
        if(getline(issa, a, '.')){
            if(getline(issb, b, '.')){
                removeLeadingZeros(a);
                removeLeadingZeros(b);
                if(a != b){
                    if(a.length() == b.length()){
                        return a > b ? 1: -1;
                    } else {
                        return a.length() > b.length() ? 1 : -1;
                    }
                }
            } else {
                if(a == "0"){
                    while(getline(issa, a, '.')){
                        removeLeadingZeros(a);
                        if(a.length()) return 1;
                    }
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            if(getline(issb, b, '.')){
                if(b == "0"){
                    while(getline(issb, b, '.')){
                        removeLeadingZeros(b);
                        if(b.length()) return -1;
                    }
                    return 0;
                } else {
                    return -1;
                }
            } else {
                return 0;
            }
        }
    }
}
