#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<string> split_string(string);

// Complete the bomberMan function below.

bool isValid(ll i, ll j, ll r, ll c){
    return (i>=0 && i<r && j>=0 && j<c);
}

vector<string> bomberMan(int n, vector<string> grid) {

    if(n == 0 || n == 1){
        return grid;
    }
    ll r = grid.size(), c = grid[0].length();

    if(n%2 == 0){
        for (ll i = 0; i < r; i++)
        {
            for (ll j = 0; j < c; j++)
            {
                grid[i][j] = 'O';
            }
        }
        return grid;
    }
    
    vector<string> temp_grid(r);

    pair<ll, ll> * move = new pair<ll, ll>[4];
    move[0] = make_pair(0,1);
    move[1] = make_pair(1,0);
    move[2] = make_pair(0,-1);
    move[3] = make_pair(-1,0);
    n = ((n/2)%2)+2;
    while(n--){
        for (ll i = 0; i < r; i++)
        {
            temp_grid[i] = grid[i];
        }
        
        for (ll i = 0; i < r; i++)
        {
            for (ll j = 0; j < c; j++)
            {
                bool flag = true;
                if(grid[i][j] == 'O'){
                    temp_grid[i][j] = '.';
                    flag = false;
                } else {
                    for (ll k = 0; k < 4; k++)
                    {
                        ll cr = i+move[k].first, cc = j+move[k].second;
                        if(isValid(cr, cc, r, c) && grid[cr][cc] == 'O'){
                            temp_grid[i][j] = '.';
                            flag = false;
                        }
                    }
                }
                if(flag){
                    temp_grid[i][j] = 'O';
                }
                
            }
            
        }
        for (ll i = 0; i < r; i++)
        {
            grid[i] = temp_grid[i];
        }
    }

    for (ll i = 0; i < grid.size(); i++)
    {
        cout<<grid[i]<<endl;
    }
    

    return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rcn_temp;
    getline(cin, rcn_temp);

    vector<string> rcn = split_string(rcn_temp);

    int r = stoi(rcn[0]);

    int c = stoi(rcn[1]);

    int n = stoi(rcn[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
