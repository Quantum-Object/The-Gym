#include <iostream>
#include <vector>
#include <climits>

using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> dp(k + 1, LLONG_MAX);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] <= k) {
            dp[a[i]] = 1;
        }
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (i - a[j] >= 0 && dp[i - a[j]] != LLONG_MAX) {
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
            }
        }
    }

    if (dp[k] == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << dp[k] << endl;
    }

    return 0;
}
