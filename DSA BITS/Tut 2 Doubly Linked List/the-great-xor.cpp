#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// Complete the theGreatXor function below.
long theGreatXor(long x) {

    ll ans = 0, pos = 0;
    while(x){
        if((x&1) == 0){
            ans += ((ll)1<<pos);
        }
        pos++;
        x /= 2;
    }

    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long x;
        cin >> x;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long result = theGreatXor(x);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
