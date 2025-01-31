#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using ll=long long;
using namespace std;
int MOD = 1e9+7;

int sd(int n){
    int s=0; 
    while (n>0){
        s+=n%10;
        n/=10;
    }
    return s;
};

ll qSlove(int b, ll c){
    double x=-b+sqrt(b*b-4*c);
    x/=2;
    if ((ll) x == x)
        return (ll) x;
    return -1;
}


int main() {
    int t;
    cin >> t;
    int n,k;
    while(t-->0){
        cin >> n >> k;
        vector<int> a(n);
        for (int i=0;i<n;i++)cin>>a[i];
        map<ll,int> x;
        for (int i=0;i<n;i++){
            ll m=i*(n-1-i)+n-1;
            if (x.count(m))
                x[m]=1;
            else x[m]++;
        }
        for (int i=1;i<n;i++){
            ll m=(i*(n-i));
            if (x.count(m))
                x[m]=((a[i]-a[i-1]));
            else x[m]+=(ll(a[i]-a[i-1]));
        }
        int c;
        while (k-->0){
            cin >> c;
            cout << x[c] <<" ";
        }
        cout << endl;
    }
   
    }
    



// 5 3 can you make them equal  ??  yes 
// 1 1 now we have --> 1 5 can you make them equal yes 1-3 5-3 -> 2 2
//so ye but wait we need to make it using one x;;!!!!!! hmmmmmmmmm
// 10 5 4 16 