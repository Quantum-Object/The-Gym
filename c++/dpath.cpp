#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;  


ll dp(int n, vector<vector<char> >& a, vector<vector<ll> >& x, int i, int j) {
    
    if (i < 0 || j < 0)
        return 0;
    
   
    if (a[i][j] == '*')
        return 0;
    
   
    if (x[i][j] != -1)
        return x[i][j];

   
    if (i == 0 && j == 0)
        return x[i][j] = 1;

   
    x[i][j] = (dp(n, a, x, i - 1, j) + dp(n, a, x, i, j - 1)) % MOD;

    return x[i][j];
}

int main() {
    int n;
    cin >> n;

    vector<vector<char> > a(n, vector<char>(n));
    vector<vector<ll> > x(n, vector<ll>(n, -1));  
    
   
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            a[i][j] = s[j];  
        }
    }

   
    cout << dp(n, a, x, n - 1, n - 1) << endl;

    return 0;
}
