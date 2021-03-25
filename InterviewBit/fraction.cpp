// https://www.interviewbit.com/problems/fraction/

typedef long long ll;

string Solution::fractionToDecimal(int A, int B) {
    if(A == 0) return "0";
    bool pos = (A>=0 == B>=0);
    ll a = abs((ll)A), b = abs((ll)B);
    ll g = __gcd(a, b);
    a /= g;
    b /= g;
    ll q = a/b, r = a%b;
    string res = pos?to_string(q):"-"+to_string(q);
    if(r) res += ".";
    else return res;
    ll dividend = a, i = 0;
    string decimal = "", key;
    unordered_map<string, ll> index;
    while(r){
        dividend = r*10;
        q = dividend/b;
        r = dividend%b;
        key = to_string(q)+","+to_string(r);
        if(index.count(key)){
            // repeat
            string rep = decimal.substr(index[key]);
            return res+decimal.substr(0, index[key])+"("+rep+")";
        }
        index[key] = i;
        decimal.push_back(q+'0');
        i++;
    }
    return res+decimal;
}
