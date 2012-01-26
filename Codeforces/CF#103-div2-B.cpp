#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int x[2000], y[2000], r[2000];

int main (int argc, const char * argv[])
{
    int x1, y1, x2, y2, n, ret = 0;
    cin >> x1>>y1>>x2>>y2;
    cin >> n;
    if (x1>x2) swap(x1, x2);
    if (y1>y2) swap(y1, y2);
    for (int i=0; i<n; i++)
        cin >> x[i] >> y[i] >> r[i];
    //y1
    for (int i=x1; i<=x2; i++)
    {
        bool flag1 = false, flag2 = false;
        for (int j=0; j<n; j++) {
            if (flag1 == false && (x[j]-i)*(x[j]-i) + (y[j]-y1)*(y[j]-y1) <= r[j]*r[j])
                flag1 = true;
            if (flag2 == false && (x[j]-i)*(x[j]-i) + (y[j]-y2)*(y[j]-y2) <= r[j]*r[j])
                flag2 = true;    
        }
        if (!flag1) ret++;
        if (!flag2) ret++;
    }
    for (int i = y1+1; i<y2; i++)
    {
        bool flag1 = false, flag2 = false;
        for (int j=0; j<n; j++) {
            if (flag1 == false && (x[j]-x1)*(x[j]-x1) + (y[j]-i)*(y[j]-i) <= r[j]*r[j])
                flag1 = true;
            if (flag2 == false && (x[j]-x2)*(x[j]-x2) + (y[j]-i)*(y[j]-i) <= r[j]*r[j])
                flag2 = true;    
        }
        if (!flag1) ret++;
        if (!flag2) ret++;
    }
    cout << ret << endl;
    return 0;
}

