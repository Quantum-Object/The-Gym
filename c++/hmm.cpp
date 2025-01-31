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

bool enq(const pair<int,int> &p){
    return p.first*2>p.second;
}

int solve0(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    bool f=0;
    for (int i=0;i<n-1 && !f;i++)
        f=enq(make_pair(min(a[i],a[i+1]),max(a[i],a[i+1])));

    cout << (f?"YES":"NO") << endl;
    return 0;
}

void solve1(){
    set<int> x;
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    x.insert(b+a);
    x.insert(c-b);
    x.insert(d-c);
    cout << 3-x.size()+1 << endl;
}

void solve2(){
    int  n,m;
    int c;
    cin >> n >> m;
    vector<int> a(n*m);
    for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
                {
                    cin >> c;
                    a[c]=i;
                }
        }
    vector <int> x(n);
    for (int i=0;i<n;i++){
        x.push_back(a[i]);
    }
    bool f=true;
    for (int i=n;i<n*m && f;i++)
        f=x[i%n]==a[i];
    if (f)
        {
            for (auto i : x)
                cout << i+1 << " ";
            cout << endl;
        }
    else cout << -1 << endl;
}
void solve(){
    int n,k,c;
    int ans=0;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0;i<n;i++)
        cin >> a[i];
    sort(a.begin(),a.end());
    int j=n-1;
    for (int i=0;i<j;){
        if(a[i]+a[j]==k){
            ans++;
            i++;j--;
        }
        else if (a[i]+a[j]>k)
            j--;
        else i++;
    }
    cout << ans << endl;

}
void s(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    int i=0;
    for (;i<n-1;i++){
        if (a[i]<=a[i+1]){
            a[i+1]-=a[i];
            a[i]=0;
        }
        else 
            break;
    }
    if (i==n-1)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
}



void bfs(int start, const vector<vector<int> >& graph, vector<bool>& visited, vector<int>& component) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        component.push_back(node);

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// Function to find all connected components
vector<vector<int> > findAllConnectedComponents(int n, const vector<vector<int> >& graph) {
    vector<bool> visited(n + 1, false); // To track visited nodes
    vector<vector<int> > components;    // To store all connected components

    for (int i = 1; i <= n; ++i) { // Assuming nodes are 1-indexed
        if (!visited[i]) {
            vector<int> component;
            bfs(i, graph, visited, component);
            components.push_back(component);
        }
    }
    return components;
}

void g(){
    int n,m1,m2;
    cin >> n >> m1 >> m2;
    vector<vector<int> > f(n);
    int a,b;
    for (int i=0;i<m1;i++){
        cin >> a >> b;
        f[a-1].push_back(b-1);
        f[b-1].push_back(a-1);
    }
    vector<vector<int> > g(n);
    for (int i=0;i<m2;i++){
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    vector<vector<int> > components = findAllConnectedComponents(n, g);
    for (int i=0;i<n;i++){
        cout << i << ":" ;
        for (int x:components[i])
            cout << x << " " ;
        cout << endl;
    }

    

}
int main(){
    int t;
    cin >> t;
    while (t-->0)
        g();
    return 0;
}

