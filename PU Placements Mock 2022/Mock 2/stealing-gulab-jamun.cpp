// https://www.hackerrank.com/contests/placements-2021-mock-2/challenges/stealing-gulab-jamun

// There are 4 guys who love gulab jamuns. So they plan to steal gulab jamuns from the mess while no one is looking. Since they are very fond of gulab jamuns, once a guy takes how many he wants, the next one will take exactly r (r is not known but r>1) times the amount of gulab jamuns than the previous guy.

// For ex: if the first guy take 2 gulab jamuns and r is 2 then the next will take 4 then 8 and finally 16. But each one of them have identical bags each of capacity n. So a guy can carry atmost n gulab jamuns in his bag. It is known that the number of ways that the guys could have stolen the gulab jamuns is m. Given the value of m, find the least possible value of n.

// Input Format

// A single integer T denoting the number of test cases

// A single integer m (1 ≤ m ≤ 10^15) — the number of ways the guys might have stolen the gulab jamuns.

// Constraints

// T<=15

// 1 ≤ m ≤ 10^15

// Output Format

// For each test case Print the minimum value of n — the maximum amount of gulab jamuns that a bag can carry followed by a new line.

// If there is no such possible n for a given m, print -1

// Sample Input 0

// 3
// 1
// 8
// 10
// Sample Output 0

// 8
// 54
// -1
// Explanation 0

// There are three test cases-

// In the first case the smallest n that leads to exactly one way of stealing gulab jamuns is n = 8, whereas the amounts of stolen gulab jamuns are (1, 2, 4, 8) (the number of gulab jamuns stolen by each of the them).

// In the second sample case the smallest n that leads to exactly 8 ways is n = 54 with the possibilities: (1, 2, 4, 8),  (1, 3, 9, 27),  (2, 4, 8, 16),  (2, 6, 18, 54),  (3, 6, 12, 24),  (4, 8, 16, 32),  (5, 10, 20, 40),  (6, 12, 24, 48).

// There is no n leading to exactly 10 ways of stealing gulab jamuns in the third sample case.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll get_ways(ll n){
    ll cube_root = 0;
    while(cube_root*cube_root*cube_root <= n) cube_root++;
    cube_root--;
    ll res = 0;
    while(cube_root >= 2){
        res += (n/(cube_root*cube_root*cube_root));
        cube_root--;
    }
    return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ll t;
    cin>>t;
    while(t--){
        ll m;
        cin>>m;
        // FT first T
        ll lo = 1, hi = LLONG_MAX, mid;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(m <= get_ways(mid)){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        if(get_ways(lo) == m) cout<<lo<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
