#include <iostream>
#include<cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;
using ll=long long;
ll MOD=1e9+7;

int maxDig(int x){
    int m=x%10;
    while (x>0){
        m=max(m,x%10);
        x/=10;
    }
    return m;
}
int main(){
    int  n;
    cin >> n;
    int c=0;
    while (n>0){
        n=n-maxDig(n);
        c++;
    }
    cout << c << endl;

}