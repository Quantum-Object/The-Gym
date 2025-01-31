#include <iostream>
#include<cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;
using ll=long long;
ll MOD=1e9+7;
vector<int> d(500000+1);

int dfs(int i,vector< vector<int > > &g, vector<bool> &visit){
   int c=1;
   visit[i]=true;
   for (int x: g[i]){
    if(!visit[x])
        c+=dfs(x,g,visit);
   }
   return c;
}

void solve(){
    int n,m,c1,c2,c3;
    cin >> n >> m;
    vector<int> a(n);
    vector< vector<int> > g(n);
    for (int i=0;i<m;i++){
        cin >> c1;
        if (c1!=0)
            cin >> c3;
        for(int k=0;k<c1-1;k++){
            cin >> c2;
            g[c3-1].push_back(c2-1);
        }
    }
    for (int i=0;i<n;i++){
        for (int x:g[i]){
            g[x].push_back(i);
        }
    }


    for (int i=0;i<n;i++){
        vector<bool> visit(n,false);
        cout << dfs(i,g,visit) << " ";
    }
    cout << endl;




}


int main(){
    int t;
    t=1;
    while (t-->0)
        solve();
    return 0;
}