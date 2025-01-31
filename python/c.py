MOD=10e9+7


def solve1():
    t = int(input())  
    
    for _ in range(t):
        k,n= map(int, input().split())
        ans=1
        for _ in range(n):
            ans*=k
            ans%=MOD
        print(int(ans))
        

        
print(pow(100000,20)%MOD)