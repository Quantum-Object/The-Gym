#include <iostream>
#include<cmath>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>


using ll= long long;
using namespace std;
ll f(int x,int n,vector<ll>& a){
    ll ans=0;
    ans+=(x/n)*a[n];
    ans+=a[n]-a[x/n];
    ans+=a[x%n-(n-x/n)];
    return ans;
}
int main(){
    int t;
    cin >> t;
    int n,q;
    while (t-->0){
        cin >> n >> q;
        vector<ll> a(n+1);a[0]=0;
        for (int i=0;i<n;i++){
            cin >> a[i+1];
            a[i+1]+=a[i];
        }
        int x,y;
        while (q-->0){
            cin >> x >> y;
            cout << f(y,n,a)-f(y,n,a) << endl;


        }

    }
    
    }

   // 1 2 3 - 2 3 1 - 3 1 2
   // 1 2 3 - 4 5 6 - 7 8 9