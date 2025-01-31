#include <iostream>
#include<cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>


using ll=long long;
using namespace std;
int MOD = 1e9+7;


int main(){
    int t;
    cin >> t;
    while (t-->0){
        int n,k;
        cin >> n >> k;
        vector<ll> a(n+1);
        a[0]=0;
        for(int i=k;i<n+k;i++){
            a[i-k+1]=a[i-k]+i;
        }


        ll m=LONG_MAX;
        for (int i=1;i<=n;i++){
            m=min(m,abs(a[i]-(a[n]-a[i])));
        }

        cout << m << endl;
    
    }
    return 0;
}