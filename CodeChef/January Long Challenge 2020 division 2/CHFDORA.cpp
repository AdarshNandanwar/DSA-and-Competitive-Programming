#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll **arr, ll n, ll m, ll i, ll j)
{
    ll ans = 1, radius = 1;

    while (0 <= (i - radius) && (i + radius) < n && 0 <= (j - radius) && (j + radius) < m)
    {
        if (arr[i + radius][j] == arr[i - radius][j] &&
            arr[i][j + radius] == arr[i][j - radius])
        {
            ans++;
            radius++;
        } else {
            break;
        }
    }
    return ans;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, ans = 0;
        cin >> n >> m;
        ll **arr = new ll *[n];
        for (ll i = 0; i < n; i++)
        {
            arr[i] = new ll[m];
            for (ll j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                ans += solve(arr, n, m, i, j);
            }
        }

        cout << ans << endl;

        for (ll i = 0; i < n; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }

    return 0;
}