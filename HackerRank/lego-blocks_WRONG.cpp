// WRONG! This solution allows full verticle break line

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll *arr = new ll[m+1]();
        arr[0] = 1;
        for (ll i = 1; i <= m; i++)
        {
            arr[i] = arr[i - 1];
            if (i > 1)
            {
                arr[i] += ((((ll)1 << n) - 1) * arr[i - 2]);
            }
            if (i > 2)
            {
                arr[i] += ((((ll)1 << (2 * n)) - (2 * ((ll)1 << n)) + 1) * arr[i - 3]);
            }
            if (i > 3)
            {
                arr[i] += ((((ll)1 << (3 * n)) - (3 * ((ll)1 << (2 * n))) + (3 * ((ll)1 << n)) + 5) * arr[i - 4]);
            }
        }


        // for (ll i = 0; i <= m; i++)
        // {
        //     cout<<arr[i]<<" ";
        // }cout<<endl;
        
        cout << arr[m] << endl;

        delete[] arr;
    }
    return 0;
}