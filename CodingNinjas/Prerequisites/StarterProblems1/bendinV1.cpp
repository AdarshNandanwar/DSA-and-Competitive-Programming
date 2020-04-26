#include<bits/stdc++.h>
using namespace std;

int coordinate(int , int, int, int);

int main()
{
    freopen("bendin.txt", "r", stdin);
    freopen("bendout.txt", "w", stdout);

    int x1,x2,x3,x4,y1,y2,y3,y4,a1,a2,a3,area;
    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;

    a1=abs((x1-x2)*(y1-y2));
    a2=abs((x3-x4)*(y3-y4));

    int x5,x7,y5,y7;
    
    x5=coordinate(x1,x2,x3,x4);
    y5=coordinate(y1,y2,y3,y4);

    x7=coordinate(x2,x1,x4,x3);
    y7=coordinate(y2,y1,y4,y3);

    a3=abs((x5-x7)*(y5-y7));

    area=a1+a2-a3;
    cout<<area;

    return 0;
}

int coordinate(int x1, int x2, int x3, int x4)
{
    if((x3<=x1 && x1<=x4) || (x4<=x1 && x1<=x3))
        return x1;
    else if ((x1<=x3 && x3<=x2) || (x2<=x3 && x3<=x1))
        return x3;
    else
        return 0;
}