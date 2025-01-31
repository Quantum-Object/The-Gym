#include <iostream>
#include<cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;
using ll=long long;
ll MOD=1e9+7;

ll ks(int n,int W,vector<int> &w,vector<int> &v){

    vector<vector<ll>> dp(n+1,vector<ll>(W+1,0));


    for (int i=1;i<=n;i++){
        for (int j=1;j<=W;j++){
            if(w[i-1]<=j)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][W];
}

int main(){
    int n,W;
    cin >> n >> W;
    vector<int> w(n);
    vector<int> v(n);
    for (int i=0;i<n;i++)
        cin >> w[i];
    for (int i=0;i<n;i++)
        cin >> v[i];

    cout << ks(n,W,w,v) << endl;
    return 0;
}