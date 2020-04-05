#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<string> split_string(string);

/*
 * Complete the twoStacks function below.
 */

ll solve(int x, ll * a, ll * b, ll n, ll m){
    if(x < 0){
        return 0;
    }
    ll ans;
    if(n<=0 && m<=0){
        return 0;
    } else {
        if(n<=0){
            ans = 1 + solve(x-b[0], a, b+1, n, m-1);
        } else if (m<=0){
            ans = 1 + solve(x-a[0], a+1, b, n-1, m);
        } else {
            ll op1 = 1 + solve(x-b[0], a, b+1, n, m-1);
            ll op2 = 1 + solve(x-a[0], a+1, b, n-1, m);
            ans = max(op1, op2);
        }
    }
    return ans;
}

int twoStacks(int x, vector<int> a, vector<int> b) {

    ll n =a.size(), m = b.size();

    ll * arra = new ll[n];
    ll * arrb = new ll[m];
    for (ll i = 0; i < n; i++)
    {
        arra[i] = a[i];
    }
    for (ll i = 0; i < m; i++)
    {
        arrb[i] = a[i];
    }
    
    return solve(x, arra, arrb, n, m);

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string nmx_temp;
        getline(cin, nmx_temp);

        vector<string> nmx = split_string(nmx_temp);

        int n = stoi(nmx[0]);

        int m = stoi(nmx[1]);

        int x = stoi(nmx[2]);

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split_string(a_temp_temp);

        vector<int> a(n);

        for (int a_itr = 0; a_itr < n; a_itr++) {
            int a_item = stoi(a_temp[a_itr]);

            a[a_itr] = a_item;
        }

        string b_temp_temp;
        getline(cin, b_temp_temp);

        vector<string> b_temp = split_string(b_temp_temp);

        vector<int> b(m);

        for (int b_itr = 0; b_itr < m; b_itr++) {
            int b_item = stoi(b_temp[b_itr]);

            b[b_itr] = b_item;
        }

        int result = twoStacks(x, a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
