t = int(input())
while t:
    t-=1
    res = 0
    l = list(map(int,input().split())) 
    n = l[0]
    k = l[1]
    s = set()
    l = list(map(int,input().split())) 
    for i in l:
        if i+k in s or i-k in s:
            res = 1
        s.add(i)
    if res:
        print("YES")
    else:
        print("NO")