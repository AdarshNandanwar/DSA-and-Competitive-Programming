// https://www.interviewbit.com/problems/compare-version-numbers/

void isZeros(istringstream & iss){
}

int Solution::compareVersion(string A, string B) {
    long long na, nb;
    string a, b;
    istringstream issa(A), issb(B);
    while(1){
        if(getline(issa, a, '.')){
            if(getline(issb, b, '.')){
                int ia = 0, ib = 0;
                while(ia<a.length() and a[ia] == '0') ia++;
                while(ib<b.length() and b[ib] == '0') ib++;
                a = a.substr(ia);
                b = b.substr(ib);
                if(a != b){
                    if(a.length() == b.length()){
                        return a > b ? 1: -1;
                    } else {
                        return a.length() > b.length() ? 1 : -1;
                    }
                }
            } else {
                if(a == "0"){
                    while(getline(issa, a, '.')) if(a != "0") return 1;
                    return 0;
                } else {
                    return 1;
                }
            }
        } else {
            if(getline(issb, b, '.')){
                if(b == "0"){
                    while(getline(issb, b, '.')) if(b != "0") return -1;
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
