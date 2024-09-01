#include <iostream>
#include<cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using ll=long long;
using namespace std;
int MOD = 1e9+7;

ll factorial(int n){
    ll s=1;
    for (int i=0;i<n;i++) s*=i+1;
    return s;
}

void printVec(vector<int> a){
    for (int i=0;i<a.size();i++){
    cout << a[i]<< " ";}
    cout << endl;
}

int main() {
    int t;
    cin>> t;
    while (t-->0){
        int n,m;
        cin>> n >> m;
        vector<int> x(n);
        int a,b;
        fill(x.begin(),x.end(),n);
        for (int i=0;i<m;i++){
            cin >> a >> b ;
            if (a>b)
                x[b-1]=min(a-1,x[b-1]);
            else 
                x[a-1]=min(b-1,x[a-1]);
        }
        long s=0;
        int c=x[n-1];
        for(int i=n-1;i>=0;i--){
            c=min(x[i],c);
            s+=c-i;
        }
        
        cout << s << endl;
        

    }
    return 0;
    }


    // 1 |2 |3
     // 1+1+1+2=5 <1,2,3>---> 3 + 2 +1 
     // 1 2 3



// 5 3 can you make them equal  ??  yes 
// 1 1 now we have --> 1 5 can you make them equal yes 1-3 5-3 -> 2 2
//so ye but wait we need to make it using one x;;!!!!!! hmmmmmmmmm
// 10 5 4 16 