// https://www.hackerrank.com/contests/placements-2021-mock-2/challenges/beautiful-triplets

// Given a sequence of integers , a triplet  is beautiful if:

// Given an increasing sequenc of integers and the value of , count the number of beautiful triplets in the sequence.

// Example


// There are three beautiful triplets, by index: . To test the first triplet,  and .

// Function Description

// Complete the beautifulTriplets function in the editor below.

// beautifulTriplets has the following parameters:

// int d: the value to match
// int arr[n]: the sequence, sorted ascending
// Returns

// int: the number of beautiful triplets
// Input Format

// The first line contains  space-separated integers,  and , the length of the sequence and the beautiful difference.
// The second line contains  space-separated integers .

// Constraints

// Sample Input

// STDIN           Function
// -----           --------
// 7 3             arr[] size n = 7, d = 3
// 1 2 4 5 7 8 10  arr = [1, 2, 4, 5, 7, 8, 10]
// Sample Output

// 3
// Explanation

// There are many possible triplets , but our only beautiful triplets are  ,  and  by value, not index. Please see the equations below:




// Recall that a beautiful triplet satisfies the following equivalence relation:  where .

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'beautifulTriplets' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER d
 *  2. INTEGER_ARRAY arr
 */

int beautifulTriplets(int d, vector<int> arr) {

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = beautifulTriplets(d, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
