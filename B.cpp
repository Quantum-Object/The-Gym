#include <iostream>
#include<cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>


using ll= long long;
using namespace std;
bool check1(string s){
    int n=s.length();
    bool v=true;
    for (int i=0;i<n;i++)
        v= v && (s[i]=='1');
    return v;
}
bool check0(string s){
    int n=s.length();
    bool v=true;
    for (int i=1;i<n-1;i++)
        v= v && (s[i]=='0');
    v= v && (s[0]=='1') && (s[n-1]=='1');
    return v;
}


int main(){
    int t;
    cin >> t;
    while (t-->0){
        int n;
        string s;
        cin >> n >> s;
        int x=(int)sqrt(n);
        if (!x*x==n)
            cout << "NO" << endl;
        else {
            bool v=true;
            v= v && check1(s.substr(0,x)) && check1(s.substr(n-x,n));
            for (int i=x;i<n-x;i+=x)
                v= v && check0(s.substr(i,i+x));
            if (v)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;

        }
        
}}