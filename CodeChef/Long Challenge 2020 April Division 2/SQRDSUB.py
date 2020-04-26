t = int(input())
for i in range(t):
    n = int(input())
    arr = input().split()
    for i in range(len(arr)):
        arr[i] = int(arr[i])
    left_odd = [0]*n
    for j in range(1,n,1):
        if arr[j-1]%2 == 1:
            left_odd[j] = left_odd[j-1]+1
    right_odd = [0]*n
    for j in range(n-2, -1, -1):
        if arr[j+1]%2 == 1:
            right_odd[j] = right_odd[j+1]+1

    sum = (n*(n+1))/2
    for j in range(n):
        if arr[j]%4 == 2:
            sum -= (left_odd[j]+1)*(right_odd[j]+1)
    print(int(sum))