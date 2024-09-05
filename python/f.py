t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    sum=0
    mod = int(1e9 + 7)
    for i in range(n):
        sum+=a[i]
        sum%=mod
    ans=0
    for i in range(n):
        sum-=a[i]
        ans+=a[i]*sum
        ans%=mod
    print(ans)
        