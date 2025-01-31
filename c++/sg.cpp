#include <iostream>
#include <algorithm>
#include <string>

using ll = long long;
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int x[26], y[26];
    fill(x, x + 26, -1);
    fill(y, y + 26, -1);

    for (int i = 1; i < a.length(); i++) {
        if (x[a[i] - 'a'] == -1) {
            x[a[i] - 'a'] = i;
        }
    }

    for (int i = b.length() - 2; i >= 0; i--) {
        if (y[b[i] - 'a'] == -1) {
            y[b[i] - 'a'] = i;
        }
    }
    int l=-a.length();
    int j = -1;
    for (int i = 0; i < 26; i++) {
        if (x[i] != -1 && y[i] != -1 && y[i] - x[i] > l) {
            j = i;
            l=y[i] - x[i];
        }
    }
    if (j==-1)
        cout << j << endl;
    else {
    int i = 1;
    cout << a[0];
    while (a[i] != 'a' + j) {
        cout << a[i++];
    }

    i = b.length() - 2;
    while (b[i] != 'a' + j) {
        i--;
    }

    while (i < b.length()) {
        cout << b[i++];
    }

    cout << endl;

    return 0;
    
}}