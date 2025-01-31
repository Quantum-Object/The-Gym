#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>


using namespace std;



using ll=long long;
int  MOD = 998244353;
int countDiv(ll n,ll x){
    int c=0;
    while (n%x==0){
        c++;
        n/=x;
    }
    return c;
}

void solve(){
    ll n,d;
    cin >> n >> d;
    cout << "1 ";
    if (n>=3 || d%3==0)
        cout << "3 ";
    if (d==5)
        cout << "5 ";
    if (d==7 || n>=3)
        cout << "7 ";
    // for 9 we need to check 
    if (d==9 || (d%3==0 && n>=3) || n>=6)
        cout << "9";
    cout << endl;
}
int maxoo(vector<int> &a,int n){
    int c=0;
    int m=0;
    for (int i=0;i<a.size();){
        while (a[i++]==n){
            c++;
        }
        m=max(m,c);
        c=0;
    }
    return m;
}
set<ll> seeet(vector<int> &a,int n){
    set<ll> s;
    ll sm=0;
    ll mx=0;
    ll mn=0;
    s.insert(sm);
    for (int i=0;i<a.size();i++){
        sm+=a[i];
        mx=max(mx,sm-*s.begin());
        mn=min(mn,sm-*s.rbegin());
        s.insert(sm);
    }
    set<ll> ans;

    while (mn<=mx){
        ans.insert(mn);
        mn++;
  
    }
    return ans;
}

void solvee(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++)
        cin >> a[i];
    vector<int> b;
    vector<int> c;
    set<int> s;
    int i=0;
    for (;i<n && abs(a[i])==1;i++)
        b.push_back(a[i]);
    int wow=i;
    i++;
    while (i<n)
        c.push_back(a[i++]);
    ll ans=0;
    set<ll> x= seeet(b,b.size());               
    set<ll> y= seeet(c,c.size());
    for (auto &xx : x){
        y.insert(xx);
    }
    if (wow<n){
    ll mn=0;
    ll mx=0;
    ll sm=0;
    for (int i=wow+1;i<n;i++){
        sm+=a[i];
        mn=min(mn,sm);
        mx=max(mx,sm);
    }
    sm=0;
    for (int i=wow-1;i>=0;i--){
        sm+=a[i];
        mn=min(mn,sm);
        mx=max(mx,sm);
    }
    while (mn<=mx){
        y.insert(mn+a[wow]);
        mn++;
    }
    cout << y.size() << endl;

    for (auto &xx : y){
        cout << xx << " ";
    }
    cout << endl;
    }
    else{
        cout << x.size() << endl;
        for (auto &xx : x){
            cout << xx << " ";
        }
        cout << endl;
    }
}
    

void solve1(){
    int n;
    cin >> n;
    vector<vector<int > > a(2,vector<int>(n));
    for (int i=0;i<n;i++)
        cin >> a[0][i];
    for (int i=0;i<n;i++)
        cin >> a[1][i];
    int m=0;
    for (int i=0;i<n;i++)
        if (a[0][i]+a[1][i]>a[0][m]+a[1][m])
            m=i;
    ll sm=0;
    for (int i=0;i<n;i++){
            sm+=max(a[0][i],a[1][i]);
    }
    ll ans=-INFINITY;
    for (int i=0;i<n;i++){
        ll x=ans;
       ans=max(sm+min(a[0][i],a[1][i]),ans);
       if (ans!=x)
            cout << i << endl;
    }

    cout << ans << endl;
    
}

void c(){
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i=0;i<n;i++)
        cin >> a[i];
    int x=0;
    int c=0;
    int sm=0;
    while (sm<n*m){
        string s="";
        for (int i=x;i<m-x;i++){
               s+=a[x][i];
            }
        for (int i=x+1;i<n-x;i++){
               s+=a[i][m-x-1];
               }
        for (int i=m-x-2;i>=x;i--){
               s+=a[n-x-1][i];
               
            }
        for (int i=n-x-2;i>x;i--){
               s+=a[i][x];
               
            }
        s+=s[0];
        s+=s[1];
        s+=s[2];
        cout << s << endl;
        for (int i=0;i<s.size()-3;i++){
            if (s.substr(i, 4)=="1543"){
                c++;
            }
        sm+=s.size()-3;
        }
        x++;
        
}
    cout << c << endl;
}
    

    
int main() {
    int t;
    cin >> t;
    while (t-->0)
        c();
}



// 1 2  0  1 -4 -1 
// 1 2 -1 4 -1 -3 

