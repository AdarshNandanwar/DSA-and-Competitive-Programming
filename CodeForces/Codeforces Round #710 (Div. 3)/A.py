def solve():

    n, m, x = list(map(int,input().split()))
    x -= 1

    col_i = x%n;
    col_j = x//n;

    print(m*col_i+col_j+1)   


t = int(input())
for i in range(t):
    solve();