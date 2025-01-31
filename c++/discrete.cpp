#include <iostream>
using namespace std;


using ll=long long;
int  MOD = 998244353;
const int  MAX_N = 1000000;


int count(int n){
    if (n%2==1)
        return -1;
    int ans=0;
    for (int i=0;i<(1<<n);i++){
        int x=i;
        int c=0;
        while (x>0){
            if (x%2==0)
                c++;
            x/=2;
        }
    if (c==n/2)
    ans+=1;
    }
    return ans;
}



int main(){
   int t,n,m;
   cin >> t;
   while (t-->0){
    cin >> n >> m;
    bool v=true;
    while (m>=2 && v){
        v=v && (n%m!=0);
        m--;
        n%=m;
    }

    cout << (v?"YES":"NO") << endl;
   }
}