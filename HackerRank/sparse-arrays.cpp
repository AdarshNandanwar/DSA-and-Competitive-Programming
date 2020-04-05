#include <bits/stdc++.h>
#include <map>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    map<string, ll> m;
    while (n--)
    {
        string a;
        cin >> a;
        m[a]++;
    }
    ll q;
    cin >> q;
    while (q--)
    {
        string a;
        cin >> a;
        cout << m[a] << endl;
    }
    return 0;
}