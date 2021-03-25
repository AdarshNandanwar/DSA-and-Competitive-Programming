#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll intersect[400] = {0};

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
    ll countDays = 0;
    for (ll i = 1; i < 400; i++)
    {
        intersect[i] += intersect[i-1];
        // if((dayNumberJan(i) == 3) || (dayNumberJan(i) == 4 && !isLeapYear(i))){
        if((dayNumber(1, 2, i) == 6) || (dayNumber(1, 2, i) == 0 && !isLeapYear(i))){
            intersect[i]++;
            countDays++;
        }
    }
    
    // cout<<countDays<<endl;
    ll t;
    cin >> t;
    while (t--)
    {
        ll ans = 0;
        ll m1, y1, m2, y2;
        cin >> m1 >> y1 >> m2 >> y2;
        ll start_year, end_year;
        start_year = (m1<3)? y1-1: y1;
        end_year = (m2>1)? y2: y2-1;
        // cout<<start_year<<" "<<end_year<<endl;
        ll st = (start_year%400)?((start_year/400)+1):(start_year/400);
        ll en = end_year/400;
        // cout<<st<<" "<<en<<endl;
        if(st<=en){
            ans += ((en-st)*countDays);
            // cout<<ans<<endl;
            ans += (intersect[end_year%400]);
            // cout<<ans<<endl;
            if(start_year%400 == 0){
                ans -= intersect[start_year%400];
            } else {
                ans += (countDays-intersect[start_year%400]);
            }
            // cout<<ans<<endl;
        } else {
            ans += (intersect[end_year%400]-intersect[start_year%400]);
            // cout<<ans<<endl;
        }

        cout<<ans<<endl;
    }
    return 0;
}