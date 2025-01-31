#include <iostream>
#include<cmath>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>


using ll= long long;
using namespace std;



int cols=10;
int rows=10;
vector<vector <int> > a;

void randomFill(int n ){
    while (n-->0){
        int i=rand()%rows+1;
        int j=rand()%cols+1;
        a[i][j]=1;
    }
}


void  update(){
        vector<vector<int > > b;
        vector<int> v(cols+2);
        fill(v.begin(),v.end(),0);
        b.push_back(v);
        for (int i=1;i<rows;i++){
            vector<int> x(cols+2);
            fill(x.begin(),x.end(),0);
            for (int j=1;j<cols;j++){
                int c=0;
                if (a[i-1][j-1]==1)
                    c++;
                if (a[i-1][j-0]==1)
                    c++;
                if (a[i-1][j+1]==1)
                    c++;
                if (a[i][j+1]==1)
                    c++;
                if (a[i][j-1]==1)
                    c++;
                if (a[i+1][j]==1)
                    c++;
                if (a[i+1][j-1]==1)
                    c++;
                if (a[i+1][j+1]==1)
                    c++;
                if (a[i][j]==1 && c>=2 && c<4)
                    x[j]=1;
                else if (a[i][j]==0 && c==3)
                    x[j]=1;
            }
            b.push_back(x);
        }
        b.push_back(v);
        a=b;
    }

void Grid(int r,int c){
        rows=r;
        cols=c;
        for (int i=0;i<r+2;i++){
            vector<int> x(c+2);
            fill(x.begin(),x.end(),0);
            a.push_back(x);
        }
    }

void print(){
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
int main(){
    Grid(10,10);
    randomFill(90);
    print();
    update();
    print();
    }