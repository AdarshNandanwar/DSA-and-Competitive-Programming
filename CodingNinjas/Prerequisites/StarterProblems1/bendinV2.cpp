#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("bendin.txt", "r", stdin);
    freopen("bendout.txt", "w", stdout);

    int x1,x2,x3,x4,y1,y2,y3,y4,a1,a2,a3,area;
    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;

    a1=abs((x1-x2)*(y1-y2));
    a2=abs((x3-x4)*(y3-y4));

    int X1,Y1,X2,Y2;
    X1=max(x1,x3);
    X2=min(x2,x4);
    Y1=max(y1,y3);
    Y2=min(y2,y4);

    a3=abs((X1-X2)*(Y1-Y2));

    if(X2>X1 && Y2>Y1)
        area=a1+a2-a3;
    else
        area=a1+a2;

    cout<<area;
    return 0;
}