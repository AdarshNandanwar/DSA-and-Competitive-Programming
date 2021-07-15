// https://www.hackerrank.com/contests/placements-2021-mock-2/challenges/sumpy/problem

// Sarthak has recently started studying for internship tests, and he being a Maths + CS major wants an internship involving both concepts of mathematics and computer science.

// So his interviewer gives him a simple task to perform, given two numbers L and R (L <= R) print out the sum of ALL factors of all numbers(including 1 and the number iteself) from L to R (both numbers inclusive). Your job is to help him achieve his task.

// Input Format

// The first line contains T, the number of test cases.

// The next T lines contain 2 integers each, denoting L and R.

// Constraints

// 1 <= T <= 105

// 1 <= L <= R <= 106

// Output Format

// For every test case, print the answer i.e. the sum of factors of all numbers from L to R.

// Sample Input 0

// 2
// 1 4
// 5 8
// Sample Output 0

// 15
// 41
// Explanation 0

// For the first case i.e 1 to 4 we have the following factors for each number in the range. (1 : 1), (2 : 1, 2), (3 : 1, 3), (4 : 1, 2, 4)

// 1 + 1 + 2 + 1 + 3 + 1 + 2 + 4 = 15

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void calculate(vector<ll> &v){
    for(ll i = 1; i<=1000000; i++){
        for(ll j = i; j<=1000000; j+=i){
            v[j] += i;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> sieve(1000000, 0);
    calculate(sieve);
    for(int i = 1; i<=1000000; i++){
        sieve[i] += sieve[i-1];
    }

    ll t;
    cin>>t;
    while(t--){
        ll l,r;
        cin>>l>>r;
        cout<<sieve[r]-sieve[l-1]<<endl;
    }
    return 0;
}