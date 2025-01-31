#include <iostream>
#include<cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;
using ll=long long;
ll MOD=1e9+7;

ll nw(int n,vector<int> &a){
    vector <ll> dp(n+1,0);
    for (auto k: a){
        dp[k]=1;
    }
    for (int i=1;i<=n;i++){
        for (auto k: a){;
            if (i-k>=0)
                dp[i]+=dp[i-k]%MOD;
        }
        dp[i]%=MOD;
        
    }
    return dp[n]%MOD;
}



int main(){
   int n,k;
   cin >> n >> k;
   vector <int> a(n);
   for (int i=0;i<n;i++)
    cin >> a[i];

    cout << nw(k,a) << endl;

}