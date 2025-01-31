#include <iostream>
#include<cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;
using ll=long long;
ll MOD=1e9+7;



bool isValid(const vector<vector<int>>& a, int row, const vector<pair<int, int>>& v, int k) {
    for (int j = 0; j < k; j++) {
        if (a[row][j] <= v[j].first || a[row][j] >= v[j].second) {
            return false; // If any column fails, the row is invalid
        }
    }
    return true;
}


int main(){
    int n,k,q;
    cin >> n >> k >> q;
    vector< vector <int > >  a(n,vector<int> (k));
    for (int i=0;i<n;i++){
        for (int j=0;j<k;j++)
            cin >> a[i][j];
    }
    for (int j=0;j<k;j++){
        for (int i=1;i<n;i++){
            a[i][j]=a[i-1][j] | a[i][j];
        }
    }

   
    
    vector<pair<int,int> >  v(k);
    int c,re,x;
    char in;
    while (q-->0){
        cout << q;
        cin >> c;
        for (int i=0;i<k;i++){
        pair<int,int> &p=v[i];
        p.first=a[0][i]-1;
        p.second=a[n-1][i]-1;
    }
        while (c-->0){
        cin >> re >> in >> x;
        if (in=='>')
            v[re-1].first=max(v[re-1].first,x);
        else
            v[re-1].second=min(v[re-1].second,x);
    }
    

int left = 0, right = n - 1;
        int result = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValid(a, mid, v, k)) {
                result = mid;  // Found a valid row
                right = mid - 1; // Search for earlier valid rows
            } else {
                left = mid + 1; // Search later rows
            }
        }

        cout << result << endl;
}}