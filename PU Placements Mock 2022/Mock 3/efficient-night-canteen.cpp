// https://www.hackerrank.com/contests/placements-2021-mock-3/challenges/efficient-night-canteen

/*

In order to cater to the needs of a large number of students in IIT Delhi, the mess organisers have decided to introduce the concept of a CONVEYER BELT in the Night Canteen. This would make the order placing system more efficient.

The conveyer belt has two ends - one where the chef places the dishes and the other where the person at the counter receives the dishes for further distribution. There is also a SIDE LANE in between the two ends(which makes the belt T-shaped).

The chef does not care about order numbers. He places the dishes in a random order. But the order has to be delivered on the basis of order numbers in an increasing manner(i.e 1,2,3,..,n-1,n). The role of the side lane is to bring the dishes to the desired order. There are certain rules that need to be followed regarding the side lane. The dish that enters the side lane last must leave the side lane first. Also a dish cannot re-enter the side lane once it has left.

You are given the order of dishes in which they arrive. Your task is to find if the dishes can be brought into the desired order.

image

As shown in the diagram, a dish coming from the chef can go either to the sidelane or directly for distribution.

Input Format

The first line of the input contains a number T , denoting the number of testcases. The next T lines contain the description of each testcase. For each testcase : The first line contains a number N, denoting the number of orders. The next line contains N numbers from 1 to N in the order in which the chef places the dishes.

Constraints

1 <= T <= 10

1 <= N <= 1000

Output Format

For each testcase: Print YES (case sensitive) if the dishes can brought into the desired order. Otherwise print NO (case sensitive).

Sample Input 0

1
5
5 1 2 4 3
Sample Output 0

YES
Explanation 0

imageThe five dishes can be reordered in the following way:imageimageimageimageimage

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
    ll cur = 1;
    for(int i = 0; i<n; i++){
        while(!st.empty() and st.top() == cur){
            cur++;
            st.pop();
        }
        if(v[i] == cur){
            cur++;
            while(!st.empty() and st.top() == cur){
                cur++;
                st.pop();
            }
        } else {
            st.push(v[i]);
        }
    }
    if(cur > n) cout<<"YES\n";
    else cout<<"NO\n";
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