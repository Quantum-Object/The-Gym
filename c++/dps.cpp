#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;
using ll = long long;
ll MOD = 1e9 + 7;

vector<vector<ll> > a(500 * (501) / 2, vector<ll>(501, -1));

ll f(int x, int n) {
    if (x<1 || x > n * (n + 1) / 2)
        return 0;
    if (a[x][n] != -1)
        return a[x][n];
    ll ans;
    if (n == 1 && x == 1)
        ans = 1;
    else
        ans = (f(x - n, n - 1) + f(x, n - 1)) % MOD;
    a[x][n] = ans;
    return ans;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < 500 * (501) / 2; i++) {
        for (int j = 0; j < 501; j++) {
            a[i][j] = -1;
        }
    }

    if ((n * (n + 1) % 4 != 0))
        cout << 0 << endl;
    else
        cout << f(n * (n + 1) / 4, n) << endl;

    return 0;
}