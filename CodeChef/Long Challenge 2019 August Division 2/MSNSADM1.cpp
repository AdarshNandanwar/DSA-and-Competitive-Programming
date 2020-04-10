#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, max_points = 0;
        cin>>n;
        int * A = new int[n];
        int * B = new int[n];
        int * points = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin>>A[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin>>B[i];
        }
        for (int i = 0; i < n; i++)
        {
            points[i] = 20*A[i] - 10*B[i];
            if(points[i]<0){
                points[i] = 0;
            }
            max_points = max(max_points, points[i]);
        }
        cout<<max_points<<endl;
        delete [] A;
        delete [] B;
        delete [] points;
    }
    return 0;
}