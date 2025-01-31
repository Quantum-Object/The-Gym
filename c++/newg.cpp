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
vector< set<int > > g(1500001);
vector<bool> vis(1500001,false);
vector<int> s(1500001,0);
vector<int> d(1500001,0);

void dfs(int i,int x){
    if (vis[i]) return;
    vis[i]=true;
    d[i]=x;
    s[x]++;
    for (int j: g[i]){
        dfs(j,x);
    }
    
}

void solve(){
    int n,m,a,b;
    cin >> n >> m;

    for(int i=0;i<m ;i++){
        cin >> a >>b;
        g[a-1].insert(b-1);
        g[b-1].insert(a-1);
    }
    for (int i=0;i<n;i++) dfs(i,i);
    bool f=true;
    for(int i=0;i<n && f;i++){
        f=f && (g[i].size()+1==s[d[i]]);
    }
    cout << (f?"YES":"NO") << endl;

}

vector<multiset<char> > p(300001);
vector< vector <int> > gr(300001);
vector<bool> vist(300001,false);

void dfs2(int i, int x, const string& s) {
    if (vist[i]) return;

    vist[i] = true;
    p[x].insert(s[i]);

    for (int j : gr[i]) {
        dfs2(j, x, s);
    }
}


vector< set<int> > pth(300001);
vector <int> state(300001,0);
bool f=true;





void solve2() {
    int n, m, a, b;
    string s;
    cin >> n >> m >> s;

    // Resize vectors properly
    p.resize(n);
    gr.resize(n);
    vist.assign(n, false);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--, b--;
        gr[a].push_back(b);
    }

    vector<int> inD(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j : gr[i]) {
            inD[j]++;
        }
    }

    vector<int> tp;
    queue<int> q;

    for (int i = 0; i < n; i++)
        if (inD[i] == 0) q.push(i);

    while (!q.empty()) {
        int j = q.front();
        q.pop();
        tp.push_back(j);

        for (int i : gr[j]) {
            inD[i]--;
            if (inD[i] == 0) q.push(i);
        }
    }

    if (tp.size() < n) {
        cout << -1 << endl;
        return;
    }

    vector<int> dp(n,0);
    int mx=0;

    for (char j = 'a'; j <= 'z'; j++) {
        dp.assign(n,0);
       for (int x : tp){
        if (s[x]==j) dp[x]++;
        mx=max(mx,dp[x]);
        for (int i : gr[x])
            dp[i]=max(dp[x],dp[i]);

    }

   
}
 cout <<  mx << endl;
}


int main(){
    solve2();
    return 0;
}