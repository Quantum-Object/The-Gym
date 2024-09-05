#include <iostream>
#include<cmath>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>


using ll= long long;
using namespace std;


int main(){
    int t;
    cin >> t;
    while (t-->0){
        int n;
        vector<int> a(n);
        unordered_set<int> h;
        int p=0;
        for (int i=0;i<n;i++) {a[i]=-1;cin >> (a[i]);}
        string s;
        cin >> s;
        vector<int> ans(n);
        for (int i=0;h.size()<n;i++){
            int c=0;
            vector<int> v;
            while (h.find(a[i]) == h.end()){
                if (s[i]==1)
                    c++;
                h.insert(a[i]);
                v.push_back(a[i]);
                i=a[i];
            }
            for (int x:v){
                ans[x]=c;
            }
        }
        for (int i=0;i<n;i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    
    
    }