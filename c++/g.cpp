#include <iostream>
#include<cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>


using namespace std;
using ll=long long;
ll MOD=1e9+7;
// Template for vector printing
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}


vector< vector<int> > g(500001);
vector<int> vis(500001,-1);
map<int,int> mp;


void dfs(int i,int n){
    
    if (vis[i]!=-1)
        return;
    vis[i]=n;
    if (!mp.count(n))
        mp[n]=1;
    else mp[n]++;

    for ( int x: g[i]){
       
        dfs(x,n);
    }
}




void solve(){
    int n,m,a,b;
    cin >> n >> m;
    int c;
    while (m-->0){
    cin >> c;
    if(c>0)
        cin >> a;
    while (--c>0){
        cin >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
        a=b;
    }}

   
   

    for (int i=0;i<n;i++) dfs(i,i);
    




    for (int i=0;i<n;i++)
        cout << mp[vis[i]] << " ";
    cout << endl;

    

    
}

set<int> x;
set<int> y;


bool run(int i,int color){
    if (vis[i]!=-1)
        return vis[i]==color;
    bool ret=true;
    vis[i]=color;
    for (int j : g[i]){
        ret = ret && run(j,!color);
    }   
    return ret;
}


void solve1(){
    int n,m,a,b;
    cin >> n >> m;
    for (int i=0;i<m;i++){
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    bool ret=true;
    for (int i=0;i<n;i++){
        if (vis[i]==-1)
            ret = ret && run(i,1);
    }
    if (ret){
        for (int i=0;i<n;i++){
            if(vis[i])
                x.insert(i+1);
            else
                y.insert(i+1);
        }
            cout << x.size() << endl;
            for (int i:x) cout << i << " ";
            cout <<  endl;
            cout << y.size() << endl;
            for (int i:y) cout << i << " ";
            cout << endl;
        }
        else cout << -1  << endl;
    }


int main(){
    int t;
    t=1;
    while (t-->0)
        solve1();
    return 0;
}