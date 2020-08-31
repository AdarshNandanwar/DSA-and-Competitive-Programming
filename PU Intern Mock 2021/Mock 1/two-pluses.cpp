// https://www.hackerrank.com/contests/intern-2020-bpgc/challenges/two-pluses

// Method 1 (Brute Forsce)

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

vector<string> split_string(string);


ll helper(vector<string> & grid, ll i1, ll j1, ll i2, ll j2){
    ll n = grid.size(), m = grid[0].size();
    ll res = 0;
    if(i1 == i2 and j1 == j2) return 0;
    for(ll r1 = 0;; r1++){
        bool isValid1 = i1-r1>=0 and i1+r1<n and j1+r1<m and j1-r1>=0 and grid[i1-r1][j1] == 'G' and grid[i1+r1][j1] == 'G' and grid[i1][j1-r1] == 'G' and grid[i1][j1+r1] == 'G';
        if(!isValid1) break;
        for(ll r2 = 0;; r2++){
            bool isValid2 = i2-r2>=0 and i2+r2<n and j2+r2<m and j2-r2>=0 and grid[i2-r2][j2] == 'G' and grid[i2+r2][j2] == 'G' and grid[i2][j2-r2] == 'G' and grid[i2][j2+r2] == 'G';

            if(!isValid2) break;

            if(i1 == i2){
                isValid2 = isValid2 and abs(i1-i2)-1 >= r1+r2;
            }
            if(j1 == j2){
                isValid2 = isValid2 and abs(j1-j2)-1 >= r1+r2;
            }
            
            if(abs(i1-i2)-1 < r1){
                isValid2 = isValid2 and abs(j1-j2)-1 < min(r1, r2))
            }
            if(abs(j1-j2)-1 < r2){
                isValid2 = isValid2 and abs(j1-j2)-1 < min(r1, r2))
            }
            if(abs(j1-j2)-1 < r1){
                isValid2 = isValid2 and abs(i1-i2)-1 < min(r1, r2))
            }
            if(abs(j1-j2)-1 < r2){
                isValid2 = isValid2 and abs(j1-j2)-1 < min(r1, r2))
            }
            

            if(!isValid2) break;
            res = max(res, (4*r1+1)*(4*r2+1));
        }
    }
    return res;
}

// Complete the twoPluses function below.
int twoPluses(vector<string> grid) {
    
    ll n = grid.size();
    if(n == 0) return 0;
    ll m = grid[0].size();
    if(m == 0) return 0;
    
    ll ans = 0;
    
    for(ll i1 = 0; i1<n; i1++){
        for(ll j1 = 0; j1<m; j1++){
            if(grid[i1][j1] == 'B') continue;
            for(ll i2 = 0; i2<n; i2++){
                for(ll j2 = 0; j2<m; j2++){
                    if(grid[i2][j2] == 'B') continue;
                    ans = max(ans, helper(grid, i1, j1, i2, j2));
                }
            }
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    int result = twoPluses(grid);

    fout << result << "\n";

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
