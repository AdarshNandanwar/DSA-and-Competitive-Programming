#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point{
    ll x, y;
};

ll crossProduct(Point p, Point q, Point r){
    ll x1 = p.x-q.x;
    ll x2 = r.x-q.x;
    ll y1 = p.y-q.y;
    ll y2 = r.y-q.y;
    ll crossProduct = x1*y2-y1*x2;
    return crossProduct;
}

vector<Point> getConvexHull(vector<Point> points){
    vector<Point> hull;
    ll left = 0, n = points.size(), p, q, r;
    for (ll i = 0; i < points.size(); i++)
    {
        if(points[i].x < points[left].x){
            left = i;
        }
    }
    p = left;
    do{
        hull.push_back(points[p]);
        q = (p+1)%n;
        for (ll i = 0; i < n; i++)
        {
            if(crossProduct(points[p], points[q], points[i]) > 0){
                q = i;
            }
        }
        p = q;
    }while(p!=left);
    return hull;
}

int main(){
    ll n;
    cin>>n;
    vector<Point> points(n);
    for (ll i = 0; i < n; i++)
    {
        cin>>points[i].x;
    }
    for (ll i = 0; i < n; i++)
    {
        cin>>points[i].y;
    }
    
    vector<Point> hull = getConvexHull(points);

    for (ll i = 0; i < hull.size(); i++)
    {
        cout<<hull[i].x<<" "<<hull[i].y<<endl;
    }
    
    return 0;
}