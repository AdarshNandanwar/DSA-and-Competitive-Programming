// https://www.hackerrank.com/contests/placements-2021-mock-1/challenges/riturajs-magazine-clippings

// Rituraj found a magazine clipping which read out a string . He wants to know if he can form a string  using multiple clippings of  and if he can, he wants to use the minimum possible number of clippings. Also, since he is good with string manipulation he can erase parts of the clippings.

// Help Rituraj find the minimum number of clippings required to form  and if it’s not possible to form  print .

// Input Format

// Each testcase consists of 2 lines containing 1 string each

// : magazine clipping Rituraj has

// : the string Rituraj wants to construct using multiple copies of A

// Both  and  consist only of lowercase alphabet letters.

// Constraints



// Output Format

// If it is impossible to get the word , print "" (without the quotes).

// Otherwise, print the minimum number of magazine clippings , which Rituraj will need to create the word .

// Sample Input 0

// ab
// baaabba
// Sample Output 0

// 6
// Explanation 0

// String  can be formed by the bold characters like a b + a b + a b + ab + a b + a b

// Sample Input 1

// ab
// babaaab
// Sample Output 1

// 5
// Sample Input 2

// abcd
// pqacrd
// Sample Output 2

// -1
// Explanation 2

// There is no way to form  from the string 

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    string a, b;
    cin>>a>>b;
    int count = 0;
    int la = a.length(), lb = b.length();
    vector<vector<int>> next_index(la+1, vector<int>(26, la));
    for(int i = la-1; i>=0; i--){
        for(int j = 0; j<26; j++){
            next_index[i][j] = next_index[i+1][j];
            if(a[i]-'a' == j) next_index[i][j] = i;
        }
    }
    
    for(int i = 0; i<lb;){
        count++;
        int j = next_index[0][b[i]-'a'];
        if(j == la){
            cout<<-1<<endl;
            return;
        }
        while(j != la){
            j++;
            i++;
            if(i >= lb) break;
            j = next_index[j][b[i]-'a'];
        }
    }
    cout<<count<<endl;
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