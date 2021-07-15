// https://www.hackerrank.com/contests/placements-2021-mock-2/challenges/jack-and-jill-2

// A straight river is flowing nearby. Jack's house is located on the same side of river as Jill's house where Jack would like to supply a bucket of water taken from the river.

// Perpendicular distances of Jack's house and Jill's house from the flowing river are X and Y units respectively. Perpendicular orthogonal distance between the lines from Jack's house to the river and Jill's house to the river is Z, as shown in the figure.

// image

// Jack starts from his home with an empty bucket, goes to some point on the river, and then delivers the filled bucket of water to Jill's house. Jack's speed of walking with a bucket filled with water is k times slower than speed of walking with bucket without water.

// Jack wants to minimize the time taken by him to start from his home, go to the river, and end up in Jill's home, so he choose the point he fills the water from the river optimally. Find the total distance Jack will have to cover if he travels wisely and minimizes his time taken.

// Note: The answer might be large so use bigger data types for storing the variables.

// Input Format

// The first line contains the number of testcases T.

// Each testcase takes a single line with four positive numbers X, Y, Z and k as input.

// Constraints

// T  104
// 1  X  106
// 1  Y  106
// 1  Z  106
// 1  k  103
// Output Format

// For every query, print a single number denoting the answer. The answer will be considered correct if the absolute error is less than 10-3.

// Sample Input 0

// 1
// 6 7 10 3
// Sample Output 0

// 17.310749

// Method 1 (WA):

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

double get_time(const double &x, const double &y, const double &z, const double &k, const double &a){
    return sqrt(x*x+a*a)+k*sqrt(y*y+(z-a)*(z-a));
}

double get_dist(const double &x, const double &y, const double &z, const double &a){
    return sqrt(x*x+a*a)+sqrt(y*y+(z-a)*(z-a));
}

void solve(){

    double x, y, z, k;
    cin>>x>>y>>z>>k;

    // NP first Positive
    
    ll lo = 0, hi = z, mid = 0;
    while(lo<hi){
        mid = lo+(hi-lo)/2;
        if(get_time(x, y, z, k, mid) <= get_time(x, y, z, k, mid+1)){
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    double min_time = DBL_MAX, a = 0;
    for(double i = max(0.0, lo-1.0); i<=min(z, lo+1.0); i += 0.0004){
        double time = get_time(x,y,z,k,i);
        if(min_time > time){
            min_time = time;
            a = i;
        }
    }
    cout<<get_dist(x,y,z,a)<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

// Method 2 (WA):

// #include <bits/stdc++.h>
// using namespace std;
// #define MOD 1000000007
// typedef long long ll;

// ll n;

// double derivative(const double &x, const double &y, const double &z, const double &k, const double &a){
//     double d1 = a/sqrt(x*x+a*a);
//     double d2 = ((z-a)*k)/sqrt(y*y+(z-a)*(z-a));
//     return d1-d2;
// }

// double get_dist(const double &x, const double &y, const double &z, const double &k, const double &a){
//     return sqrt(x*x+a*a)+sqrt(y*y+(z-a)*(z-a));
// }

// void solve(){

//     double x, y, z, k;
//     cin>>x>>y>>z>>k;

//     // NP first Positive

//     double lo = 0, hi = z, mid = 0;
//     while(lo<hi){
//         mid = (lo+hi)/2;
//         double res = derivative(x, y, z, k, mid);
//         if(res > 0){
//             hi = mid-0.000000001;
//         } else if(res < 0) {
//             lo = mid+0.000000001;
//         } else {
//             cout<<get_dist(x,y,z,k,mid)<<endl;
//             return;
//         }
//     }
//     lo = min(lo, z);
//     hi = max(hi, 0.0);
//     cout<<min(get_dist(x,y,z,k,lo), get_dist(x,y,z,k,hi))<<endl;
// }

// int main(){

//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     ll t;
//     cin>>t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }