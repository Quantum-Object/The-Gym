import math
MOD =998244353
def solve():
        n,m= map(int, input().split())
        i=1
        s=0
        while (m-i>=n-2):
            s+=math.comb(m-i,n-2)%MOD
            i+=1
        print(((s*((n-2)%MOD)*((1<<(n-3))%MOD)%MOD))%MOD)


solve()
