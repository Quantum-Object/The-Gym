#include <iostream>
#include<cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>

using namespace std;
using ll=long long;
ll MOD=1e9+7;

int main(){
    int t,n,m,l;
    cin >> t;
    while (t-->0){
        cin >> n >> m >> l;
        vector<pair<int,int> > v;
        vector<pair<int,int> > p;
        int a,b;
        for (int i=0;i<n;i++){
            cin >> a >> b;
            v.push_back(pair<int,int>(a,b-a));
        }
        for (int i=0;i<m;i++){
            cin >> a >> b;
            p.push_back(pair<int,int>(a,b));
        }
    int i=0;
    ll  jump=1;
    int c=0;
    multiset<int> pp;
    bool flag=false;
    for (auto &d : v){
        int s=d.first;
        while (i<m && d.first> p[i].first){
            pp.insert(p[i].second);
            i++;
            
        }
        while (pp.size()>0 && jump<d.second+2){
            int x=*pp.rbegin();
            jump+=x;c++;
            pp.erase(x);
        }
        if(jump<d.second+2){
            flag=true;
            break;
        }   
    }
    if (flag)
        cout << -1 << endl;
    else 
        cout << c << endl;

} }