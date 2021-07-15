// https://www.hackerrank.com/contests/placements-2021-mock-3/challenges/largest-rectangle

/*

Skyline Real Estate Developers is planning to demolish a number of old, unoccupied buildings and construct a shopping mall in their place. Your task is to find the largest solid area in which the mall can be constructed.

There are a number of buildings in a certain two-dimensional landscape. Each building has a height, given by . If you join  adjacent buildings, they will form a solid rectangle of area .

Example

A rectangle of height  and length  can be constructed within the boundaries. The area formed is .

Function Description

Complete the function largestRectangle int the editor below. It should return an integer representing the largest rectangle that can be formed within the bounds of consecutive buildings.

largestRectangle has the following parameter(s):

int h[n]: the building heights
Returns
- long: the area of the largest rectangle that can be formed within the bounds of consecutive buildings

Input Format

The first line contains , the number of buildings.
The second line contains  space-separated integers, each the height of a building.

Constraints

Sample Input

STDIN       Function
-----       --------
5           h[] size n = 5
1 2 3 4 5   h = [1, 2, 3, 4, 5]
Sample Output

9
Explanation

An illustration of the test case follows.
image

*/


#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    vector<ll> v(n, 0);
    for(auto &i:v) cin>>i;

    stack<ll> st;
    vector<ll> next(n, n), prev(n, -1);     // lesser
    for(ll i = 0; i<n; i++){
        while(!st.empty() and v[st.top()] > v[i]){
            next[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) st.pop();

    for(ll i = n-1; i>=0; i--){
        while(!st.empty() and v[st.top()] > v[i]){
            prev[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    ll res = 0;

    for(int i = 0; i<n; i++){
        res = max(res, v[i]*(next[i]-prev[i]-1));
    }
    cout<<res<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    while(t--){
        solve();
    }
    return 0;
}