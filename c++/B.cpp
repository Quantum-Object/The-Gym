#include <iostream>
#include <algorithm>
#include <vector>

 
using namespace std;
 
int main() {
    int t, n;
    cin >> t;

    while (t-->0){
        string s;
        cin >> n >> s;
        if (n%2==0){
        vector<int> x('z'-'a'+1);
        vector<int> y('z'-'a'+1);
        fill(x.begin(),x.end(),0);
        fill(y.begin(),y.end(),0);
        for (int i=0;i<n;i++){
            if (i%2)
                x[s[i]-'a']++;
            else
                y[s[i]-'a']++;
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        cout << n << " " <<n-x[25]-y[25] << endl;
        }

        else{
            
        }
            
        }

            
    }


    }