#include<bits/stdc++.h>
#include <unordered_map>
#include <cmath>
using namespace std;
void PairSum(int *input, int n)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int key = input[i];
        if (m.count(key) == 0)
        {
            m[key] = 1; //initializing frequency value to 1 if key is not already presentin hashmap
        }
        else
        {
            m[key]++; //incrementing frequency value by 1 if key is already present inhashmap
        }
    }
    //traversing the array and checking if -key is present in hashmap
    for (int i = 0; i < n; i++)
    {
        int key = input[i];
        if (m.count(-key) != 0 && m[key] != 0)
        {
            int times = m[key] * m[-key];
            while (times != 0)
            {
                cout << min(key, (-key));
                cout << " " << max(key, (-key)) << "\n";
                times--;
            }
            m[key] = 0;
            m[-key] = 0;
        }
    }
}