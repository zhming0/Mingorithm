#include<cstring>
#include <iostream>
#include<cstdio>
using namespace std;
long long f[61][61];
//
long long ans[20];
int main (int argc, const char * argv[])
{
    f[1][1]=1;
    //ans[1]=1;
    for (int i=2; i<=60; i++) {
        //ans[i]=2;
        f[i][1]=f[i][i]=1;
        for (int j=2; j<i; j++) {
            f[i][j]=f[i-1][j]*j+f[i-1][j-1];
            //ans[i]+=f[i][j];
        }
    }
    int n,m;
    while (~scanf("%d%d",&n,&m)) {
        cout<<f[n][m]<<endl;
    }
    return 0;
}

