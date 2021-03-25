#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
typedef long long ll;

ll gcdExtended(ll a, ll b, ll *x, ll *y); 

ll modInverse(ll a, ll m) 
{ 
	ll x, y; 
	ll g = gcdExtended(a, m, &x, &y); 
	if (g != 1) {
        return -1;
    }else{ 
		ll res = (x%m + m) % m; 
        return res;
	} 
} 

ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
	if (a == 0) 
	{ 
		*x = 0, *y = 1; 
		return b; 
	} 
	ll x1, y1; 
	ll gcd = gcdExtended(b%a, a, &x1, &y1); 
	*x = y1 - (b/a) * x1; 
	*y = x1; 

	return gcd; 
} 

ll n;
ll hash_count = 0;

vector<ll> calculate(vector<ll> ex1, vector<ll> ex2, char op){
	ll m = MOD;
	vector<ll> v;
	if(op == '|'){

		ll zero = 0, one = 0, a = 0, A = 0;

		zero = ( (zero%m) + ( (ex1[0]%m) * (ex2[0]%m) )%m)%m;
		v.push_back(zero);

		one = ( (one%m) + ( (ex1[0]%m) * (ex2[1]%m) )%m)%m;
		one = ( (one%m) + ( (ex1[1]%m) * (ex2[0]%m) )%m)%m;
		one = ( (one%m) + ( (ex1[1]%m) * (ex2[1]%m) )%m)%m;
		one = ( (one%m) + ( (ex1[1]%m) * (ex2[2]%m) )%m)%m;
		one = ( (one%m) + ( (ex1[1]%m) * (ex2[3]%m) )%m)%m;
		one = ( (one%m) + ( (ex1[2]%m) * (ex2[1]%m) )%m)%m;
		one = ( (one%m) + ( (ex1[2]%m) * (ex2[3]%m) )%m)%m;
		one = ( (one%m) + ( (ex1[3]%m) * (ex2[1]%m) )%m)%m;
		one = ( (one%m) + ( (ex1[3]%m) * (ex2[2]%m) )%m)%m;
		v.push_back(one);

		a = ( (a%m) + ( (ex1[0]%m) * (ex2[2]%m) )%m)%m;
		a = ( (a%m) + ( (ex1[2]%m) * (ex2[0]%m) )%m)%m;
		a = ( (a%m) + ( (ex1[2]%m) * (ex2[2]%m) )%m)%m;
		v.push_back(a);

		A = ( (A%m) + ( (ex1[0]%m) * (ex2[3]%m) )%m)%m;
		A = ( (A%m) + ( (ex1[3]%m) * (ex2[0]%m) )%m)%m;
		A = ( (A%m) + ( (ex1[3]%m) * (ex2[3]%m) )%m)%m;
		v.push_back(A);
		
		return v;

	} else if(op == '&'){
		
		ll zero = 0, one = 0, a = 0, A = 0;

		zero = ( (zero%m) + ( (ex1[0]%m) * (ex2[0]%m) )%m)%m;
		zero = ( (zero%m) + ( (ex1[0]%m) * (ex2[1]%m) )%m)%m;
		zero = ( (zero%m) + ( (ex1[0]%m) * (ex2[2]%m) )%m)%m;
		zero = ( (zero%m) + ( (ex1[0]%m) * (ex2[3]%m) )%m)%m;
		zero = ( (zero%m) + ( (ex1[1]%m) * (ex2[0]%m) )%m)%m;
		zero = ( (zero%m) + ( (ex1[2]%m) * (ex2[0]%m) )%m)%m;
		zero = ( (zero%m) + ( (ex1[2]%m) * (ex2[3]%m) )%m)%m;
		zero = ( (zero%m) + ( (ex1[3]%m) * (ex2[0]%m) )%m)%m;
		zero = ( (zero%m) + ( (ex1[3]%m) * (ex2[2]%m) )%m)%m;
		v.push_back(zero);

		one = ( (one%m) + ( (ex1[1]%m) * (ex2[1]%m) )%m)%m;
		v.push_back(one);

		a = ( (a%m) + ( (ex1[1]%m) * (ex2[2]%m) )%m)%m;
		a = ( (a%m) + ( (ex1[2]%m) * (ex2[1]%m) )%m)%m;
		a = ( (a%m) + ( (ex1[2]%m) * (ex2[2]%m) )%m)%m;
		v.push_back(a);

		A = ( (A%m) + ( (ex1[1]%m) * (ex2[3]%m) )%m)%m;
		A = ( (A%m) + ( (ex1[3]%m) * (ex2[1]%m) )%m)%m;
		A = ( (A%m) + ( (ex1[3]%m) * (ex2[3]%m) )%m)%m;
		v.push_back(A);
		
		return v;
		
	} else {
		
		ll zero = 0, one = 0, a = 0, A = 0;

		zero = ( (zero%m) + ( (ex1[0]%m) * (ex2[0]%m) )%m)%m;
		zero = ( (zero%m) + ( (ex1[1]%m) * (ex2[1]%m) )%m)%m;
		zero = ( (zero%m) + ( (ex1[2]%m) * (ex2[2]%m) )%m)%m;
		zero = ( (zero%m) + ( (ex1[3]%m) * (ex2[3]%m) )%m)%m;
		v.push_back(zero);

		one = ( (one%m) + ( (ex1[0]%m) * (ex2[1]%m) )%m)%m;
		one = ( (one%m) + ( (ex1[1]%m) * (ex2[0]%m) )%m)%m;
		one = ( (one%m) + ( (ex1[2]%m) * (ex2[3]%m) )%m)%m;
		one = ( (one%m) + ( (ex1[3]%m) * (ex2[2]%m) )%m)%m;
		v.push_back(one);

		a = ( (a%m) + ( (ex1[0]%m) * (ex2[2]%m) )%m)%m;
		a = ( (a%m) + ( (ex1[1]%m) * (ex2[3]%m) )%m)%m;
		a = ( (a%m) + ( (ex1[2]%m) * (ex2[0]%m) )%m)%m;
		a = ( (a%m) + ( (ex1[3]%m) * (ex2[1]%m) )%m)%m;
		v.push_back(a);

		A = ( (A%m) + ( (ex1[0]%m) * (ex2[3]%m) )%m)%m;
		A = ( (A%m) + ( (ex1[1]%m) * (ex2[2]%m) )%m)%m;
		A = ( (A%m) + ( (ex1[2]%m) * (ex2[1]%m) )%m)%m;
		A = ( (A%m) + ( (ex1[3]%m) * (ex2[0]%m) )%m)%m;
		v.push_back(A);
		
		return v;
	}
}

vector<ll> parse(string s, ll i){
	if(s[i] == '#'){
		vector<ll> v = {1,1,1,1,i+1};
		hash_count++;
		return v;
	}else{
		vector<ll> ex1, ex2;
		ex1 = parse(s, i+1);
		char op = s[ex1[4]];
		ex2 = parse(s, ex1[4]+1);
		vector<ll> v;
		v = calculate(ex1, ex2, op);
		v.push_back(ex2[4]+1);
		return v;
	}
}

void solve(){

	string s;
	cin>>s;
	vector<ll> v;
	hash_count = 0;
	v = parse(s, 0);
	
	for (ll i = 0; i < 4; i++)
	{	
		ll p = v[i], q_inverse = 1, m = MOD;
		ll inverse_4 = modInverse(4, m);
		for (ll i = 0; i < hash_count; i++)
		{
			q_inverse = ((q_inverse%m)*(inverse_4%m))%m;
		}
		cout<<((p%m)*(q_inverse%m))%m<<" ";
	}cout<<endl;
	
}
 
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin>>t;
	while(t--){
		solve();
	}

	return 0;
}

// 5
// ((#&#)&#)
// ((#|#)&#)
// ((#&#)^#)
// ((#|#)&(#&#))
// (#&(#^#))