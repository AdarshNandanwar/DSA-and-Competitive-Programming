// Mehta And Bank Robbery
// Send Feedback
// One fine day, when everything was going good, Mehta was fired from his job and had to leave all the work. So, he decided to become a member of gangster squad and start his new career of robbing. Being a novice, mehta was asked to perform a robbery task in which he was given a bag having a capacity W units. So, when he reached the house to be robbed, there lay N items each having particular weight and particular profit associated with it. But, theres a twist associated, He has first 10 primes with him, which he can use atmost once, if he picks any item x, then he can multiply his profit[x] with any of the first 10 primes and then put that item llo his bag. Each prime can only be used with one particular item and one item can only have atmost one prime multiplied with its profit. Its not necessary to pick all the items. If he doesnt want to use a prime with any particular item, he can simply add the profit as it is, more specifically, 1*profit[x] for xth item will get added to its total profit, and that he can do with as many items as he wants. He cannot fill his bag more than weight W units. Each item should be picked with its whole weight, i.e it cannot be broken llo several other items of lesser weight. So, now to impress his squad, he wishes to maximize the total profit he can achieve by robbing this wealthy house.
// Input:
// First Line of input contalls two llegers N and W. Next N lines contain information of ith item, describing profit and weight of the ith item, profit and weight are separated by single space.
// Output:
// In a single line, output the maximum profit obtainable.
// Constralls:
// 1 <= N <= 2000, 1 <= W <= 2000

// 1 <= Profit[i] <= 10^9, 1 <= Weight[i] <= 2000

// SAMPLE INPUT
// 3 4

// 1 1

// 2 1

// 3 1

// SAMPLE OUTPUT
// 152

// Explanation:
// As all, the items can be picked, so maximum profit is equal to = 1 X 19 + 2 X 23 + 3 X 29 = 152

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct item_struct{
    ll value;
    ll weight;
};

bool compare(item_struct a, item_struct b){
    if(a.value == b.value){
        return a.weight < b.weight;
    } else {
        return a.value > b.value;
    }
}

ll solve(item_struct * item, ll n, ll W, ll * prime, ll p_size, ll *** dp){
    if(n<=0){
        return 0;
    }
    if(dp[n][W][p_size] != -1){
        return dp[n][W][p_size];
    }
    ll option1 = solve(item+1, n-1, W, prime, p_size, dp);
    ll option2 = 0, option3 = 0;
    if(item[0].weight <= W){
        option2 = solve(item+1, n-1, W-item[0].weight, prime, p_size, dp) + item[0].value;
        if(p_size>0){
            option3 = solve(item+1, n-1, W-item[0].weight, prime+1, p_size-1, dp) + item[0].value*prime[0];
        }
    }
    ll ans;
    ans = max(option1, max(option2, option3));
    dp[n][W][p_size] = ans;
    return ans;
}

int main()
{
    ll n, W;
    cin>>n>>W;
    ll prime[11] = {29, 23, 19, 17, 13, 11, 7, 5, 3, 2};
    item_struct * item = new item_struct[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>item[i].value;
        cin>>item[i].weight;
    }
    sort(item, item+n, compare);
    ll *** dp = new ll**[n+1];
    for (ll i = 0; i < n+1; i++)
    {
        dp[i] = new ll*[W+1];
        for (ll j = 0; j < W+1; j++)
        {
            dp[i][j] = new ll[11];
            for (ll k = 0; k < 11; k++)
            {
                dp[i][j][k] = -1;
            }
        }
    }
    
    ll ans;
    ans = solve(item, n, W, prime, 10, dp);
    cout<<ans<<endl;
    
    for (ll i = 0; i < n+1; i++)
    {
        for (ll j = 0; j < W+1; j++)
        {
            delete [] dp[i][j];
        }
        delete [] dp[i];
    }
    delete [] dp;
    delete [] item;
    return 0;
}