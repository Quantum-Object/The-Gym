#include <iostream>
#include<cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using ll=long long;
using namespace std;
void printvec(vector<int> a){
    cout << "< ";
    for (int i:a)
        cout << i << " ";
    cout << " >" <<endl;
}
int TT(vector< vector<int> > x,vector<int> a,int p ){
    vector<int> v=x[p];
    if (v.size()==0)
        return a[p];
    else{
        int m=TT(x,a,v[0]);
        for (int i=1;i<v.size();i++)
            m=min(m,TT(x,a,v[i]));
        cout << p << " :" << m << endl;
        if (p==0)
            return m+a[p];
        return min(m,(m+a[p])/2);
    }
}


int main() {
    int t;
    cin>> t;
    while (t-->0){
        int n;
        cin >> n;
        vector<vector<int> > x(n);
        vector<int> a(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        int in;
        for(int i=1;i<n;i++){
            cin>>in;
            x[in-1].push_back(i);
        }
        for (int i=0;i<n;i++){
            cout << i << ": " ;printvec(x[i]);
        }
       cout << TT(x,a,0) << endl;
    }


    }