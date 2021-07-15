// https://www.hackerrank.com/contests/placements-2021-mock-1/challenges/proud-numbers

// Following the idea of pride month, numbers also wanted to celebrate the diversity among them.

// The diversity  of a set of numbers  can be defined as the maximum of absolute differences  among each pair , in the set.

// For example the diversity of the set  will be

// .

// You are given an array  consiting of  integers, and diversity .

// You have to find the minimum possible  such that every subset of size exactly  will have at least  diversity.

// See sample input and output for more clarity.

// Note: that  may or may not be a factor of 

// Input Format

// First line contains , denoting the number of test cases to follow.

// Each test case consists of 2 lines

 

   

// : Number of integers in array 

// : Minimum diversity required

// : Space separated elements of the array 

// (It is guaranteed that such a  exists, and is less than .)

// Constraints

// for 20% points:





// for next 30% points:





// for next 30% points:





// for next 20% points:





// Output Format

// For each test case, print a single integer on a new line: minimum possible  based on the above conditions.

// Sample Input 0

// 1
// 5 2
// 4 3 1 5 6
// Sample Output 0

// 3
// Explanation 0

// All subsets of size 2:


// So, diversity of each of them is 2, 3, 4, 5, 1, 2, 3, 1, 2, 1 respectively.

// So, minimum among these is 1. But, since , we need to ensure that minimum is at least 2. Hence,  does not work.

// All subsets of size 3:


// So, diversity of each of them is 3, 4, 5, 4, 5, 5, 2, 3, 3, 3.

// So, minimum among these is 2. So for ,  is the minimum  that works.

// We can check that all >2 also work.

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

bool is_valid(vector<ll> & v, const ll & d, ll k){
    ll p1 = 0, p2 = k-1;
    while(p2<v.size()){
        if(v[p2++]-v[p1++] < d) return 0;
    }
    return 1;
}

ll n;

void solve(){
    ll d;
    cin>>n>>d;
    vector<ll> v(n);
    for(auto &i:v) cin>>i;
    sort(v.begin(), v.end());

    // FT first T
    ll lo = 1, hi = 1000000, mid;
    while(lo<hi){
        mid = lo+(hi-lo)/2;
        if(is_valid(v, d, mid)){
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    cout<<lo<<endl;
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