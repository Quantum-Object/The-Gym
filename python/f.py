
t=int(input())
while (t>0):
    t-=1
    n = int(input())
    a = list(map(int, input().split()))
    s=0
    ans=0
    mod = int(1e9 + 7)
    for i in range(n): s += a[i]
    s %= mod
    for i in range(n):
        s -= a[i]
        ans = (ans + a[i] * s) % mod
    ans = (ans * pow(n * (n - 1) // 2, mod - 2, mod)) % mod
    print(ans)