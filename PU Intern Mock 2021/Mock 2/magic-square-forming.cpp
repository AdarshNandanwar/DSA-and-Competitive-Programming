// https://www.hackerrank.com/contests/intern-2020/challenges/magic-square-forming

#include <bits/stdc++.h>

using namespace std;

bool isMagic(vector<int> & A){
    vector<int> r(3, 0), c(3, 0);
    for(int x = 0; x<9; x++){
        int i = x/3;
        int j = x%3;
        r[i] += A[x];
        c[j] += A[x];
    }
    
    return (r[0] == r[1]) and (r[1] == r[2]) and (c[0] == c[1]) and (c[1] = c[2]) and (r[0] == c[0]) and (r[0] == (A[0]+A[4]+A[8])) and (r[0] == (A[2]+A[4]+A[6]));
}

int getCost(vector<vector<int>> & s, vector<int> & A){
    int res = 0;
    for(int x = 0; x<9; x++){
        int i = x/3;
        int j = x%3;
        res += abs(s[i][j]-A[x]);
    }
    return res;
}

void helper(vector<vector<int>> & s, vector<bool> & done, vector<int> & cur, int index, int & ans){
    if(index == 9) {
        if(isMagic(cur)) ans = min(ans, getCost(s, cur));
        return;
    }
    for(int i = 1; i<=9; i++){
        if(!done[i]){
            done[i] = 1;
            cur[index] = i;
            helper(s, done, cur, index+1, ans);
            done[i] = 0;
        }
    }
}

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {

    int ans = INT_MAX;

    vector<bool> done(10, 0);
    vector<int> cur(9);

    helper(s, done, cur, 0, ans);

    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";
    fout.close();

    return 0;
}
