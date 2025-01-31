#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;
using ll = long long;
ll MOD = 1e9 + 7;

vector<int> a;

ll f(int x, int i) {
    cout << x << " " << i << endl;
    if (i<=0)
        return 0;
    if ( x==1)
        return 1;
    if (x%(a[i])!=0)
        return f(x,i-1);
    return f(x/a[i],i-1)+f(x,i-1)+f(x/a[i],i);
}

int main() {
    int n;
    cin >> n;
    int x;
    for (int i=0;i<n;i++){
        cin >> x;
        a.push_back(x);
    }
    cout << f(2520,n-1) << endl;
    return 0;
}