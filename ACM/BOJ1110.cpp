#include<cstring>
#include<cstdio>
#include <iostream>

long long f[2010][2010];
using namespace std;

int main (int argc, const char * argv[])
{
    for (int i=0; i<2001; i++) {
        f[1][i] = i;
        f[i][1] = i;
        f[0][i] = 0;
        f[i][0] = 0;
    }
    for (int i=2; i<=2000; i++)
        for (int j=2; j<=2000; j++)
            f[i][j] = f[i-1][j] + f[i][j-1];
    int t, a, b;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d %d", &a, &b);
        cout << f[a][b] << endl;
    }
    return 0;
}

