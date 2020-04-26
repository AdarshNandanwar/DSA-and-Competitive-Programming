// Hasan and Trip
// Send Feedback
// Hasan has finally finished his final exams and he decided to go in a trip among cities in Syria.
// There are N cities in Syria and they are numbered from 1 to N, each city has coordinates on plane, i-th city is in (Xi, Yi).
// Hasan is in first city and he wants to visit some cities by his car in the trip but the final destination should be N-th city and the sequence of cities he will visit should be increasing in index (i.e. if he is in city i he can move to city j if and only if i < j ).
// Visiting i-th city will increase Hasan's happiness by Fi units (including first and last cities), also Hasan doesn't like traveling too much, so his happiness will decrease by total distance traveled by him.
// Help Hasan by choosing a sequence of cities to visit which maximizes his happiness.
// Input format:
// First line contain integer N.
// Next N lines contains three integers each, i-th line contains coordinates of i-th city Xi, Yi and Fi.
// Output format:
// Output one number rounded to 6 digits after floating point, the maximum possible happiness Hasan can get. Note: If answer is 2 print 2.000000
// Constraints:
// 1 <= N <= 3,000
// 0 <= Xi, Yi, Fi <= 100,000
// Sample Input
// 3
// 0 0 1
// 3 1 1
// 6 0 9
// Sample Output
// 4.675445

#include <bits/stdc++.h>
using namespace std;

double find_happiness(double * x, double * y, double * h, double X, double Y, int n, double * dp){
    if(n == 1){
        // cout<<X<<" "<<Y<<" "<<x[0]<<" "<<y[0]<<" "<<((X-x[0])*(X-x[0]) + (Y-y[0])*(Y-y[0]))<<endl;
        return h[0] - sqrt((X-x[0])*(X-x[0]) + (Y-y[0])*(Y-y[0]));
    }
    if(dp[n] != -1){
        return dp[n];
    }
    double option1 = find_happiness(x+1, y+1, h+1, X, Y, n-1, dp);
    double option2 = h[0] - sqrt((X-x[0])*(X-x[0]) + (Y-y[0])*(Y-y[0])) + find_happiness(x+1, y+1, h+1, x[0], y[0], n-1, dp);
    double output = max(option1, option2);
    // cout<<output<<" ";
    dp[n] = output;
    return output;
}

int main()
{
    int n;
    cin>>n;
    double * x = new double[n];
    double * y = new double[n];
    double * h = new double[n];

    double * dp = new double[n+1];
    for (int i = 0; i < n; i++)
    {
        dp[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        cin>>x[i]>>y[i]>>h[i];
    }
    
    cout << setprecision (6) << fixed << h[0] + find_happiness(x+1, y+1, h+1, x[0], y[0], n-1, dp)<<endl;

    delete [] dp;
    delete [] x;
    delete [] y;
    delete [] h;
    return 0;
}