#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll intersect[1000001] = {0};

int dayNumber(int day, int month, int year)
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    year -= month < 3;
    return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}

// ll dayNumberJan(ll year)
// {
//     year--;
//     return (year + year / 4 - year / 100 + year / 400 + 1) % 7;
// }

bool isLeapYear(ll year)  
{
    if (year % 400 == 0)  
        return true;
    if (year % 100 == 0)  
        return false;
    if (year % 4 == 0)  
        return true;  
    return false;  
}  


int main()
{
    intersect[0] = 0;
    for (ll i = 1; i < 1000001; i++)
    {
        intersect[i] += intersect[i-1];
        // if((dayNumberJan(i) == 3) || (dayNumberJan(i) == 4 && !isLeapYear(i))){
        if((dayNumber(1, 2, i) == 6) || (dayNumber(1, 2, i) == 0 && !isLeapYear(i))){
            intersect[i]++;
        }
    }
    
    
    ll t;
    cin >> t;
    while (t--)
    {
        ll m1, y1, m2, y2;
        cin >> m1 >> y1 >> m2 >> y2;
        ll start_year, end_year;
        start_year = (m1<3)? y1-1: y1;
        end_year = (m2>1)? y2: y2-1;
        cout<<intersect[end_year]-intersect[start_year]<<endl;
    }
    return 0;
}