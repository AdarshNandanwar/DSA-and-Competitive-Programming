#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    scanf("%d", &n);
    if(n == 1){
        printf("1\n1 1\n");
    }else if(n == 2){
        printf("1\n2 1 2\n");
    }else if(n == 3){
        printf("1\n3 1 2 3\n");
    } else {
        printf("%d\n3 1 2 3\n", n/2);
        for (int i = 4; i <= n; i++)
        {
            i++;
            if(i<=n){
                printf("2 %d %d", i-1, i);
            } else {
                printf("1 %d", i-1);
            }
            printf("\n");
        }
    }
}
 
int main(){

    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}